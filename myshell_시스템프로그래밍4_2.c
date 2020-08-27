//
//제출년도 	: 2020
//과목명	: 시스템프로그래밍
//과제명	: simple shell program
//학번		: B411038
//이름		: 김영수


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


void readcmd(int cmdcheck, char realcmd[]){ // cmd 인자로 받으면 cmdcheck == 1 아니면 0
	char* token[1000];
	char* pipearr[1000];
	char* semi[1000];
	char* redir[1000];
	char* tmp;
	char cmd[1000];
	char cmd_semi[1000];
	char cmd_pipe[1000];
	int i;
	int j;
	int k;
	pid_t child_pid;
	int status;
	int check = -1;
	int fd;
	while(1){
		//sleep(1);
		printf("$");
		int len;
		int semi_len;
		int pipe_len=0;
		semi_len=0;
		len =0;
		int semi_check=0;
		int pipe_check=0;

		//if(fgets(cmd,sizeof(cmd),stdin)){
		if(cmdcheck){
			if(cmdcheck == 1){	// -c 옵션있는경우
				strcpy(cmd ,realcmd);	// 인자로 들어온 cmd를 setting
			}
			if(cmdcheck == 2){	// 인자없는경우 while
				if(fgets(cmd,sizeof(cmd),stdin)){	// stdin while돌며cmd받기
					len =0;
				}
				else{	// end-of-file 이면 return;
					printf("\n");
					return;
				}
			}
			if(strstr(cmd,";")){		// 명령어에 ;이 있는경우
				strcpy(cmd_semi,cmd);
				semi[semi_check] = strtok(cmd_semi,";");// ; 까지 strtok
				for(semi_check =1;;semi_check++){
					semi[semi_check] = strtok(NULL,";"); // 다음 ; 까지 명령어 strtok
					//printf("%s\n",semi[semi_check]);
					if(semi[semi_check] == NULL)
					{
						semi_len = semi_check;
						break;	
					}
				}// ; 기준으로 명령어 모두 parse
				for(k=0; k<semi_len; k++){ // 각각의 명렁어 실행준비
					tmp = strtok(semi[k]," \n");
					token[0] = tmp;	// 첫 인자 즉 exec대상
					i = 1;
					while(tmp != NULL){
						tmp = strtok(NULL, " \n");
						token[i] = tmp;
						i++;
					}
					len = i - 1;      // 마지막 NULL제외
					int j = 0;
					for (j = 1; j<len; j++){
						if (strstr(token[j], "&")){
							token[j] = NULL;
							check = 1; //background check
						}
					}
					if ((child_pid = fork()) == 0){ // child
						execvp(token[0], token);
						exit(1);
					}
					else if (child_pid != 0){
						if (check != 1){//background가 아니라면
							waitpid(child_pid, &status, 0);
						}
					}
				}
			}
			else if(strstr(cmd,">")){		// 명령어에 >이 있는경우
				strcpy(cmd_semi, cmd);
				semi[semi_check] = strtok(cmd_semi, ">");
				for (semi_check = 1;; semi_check++){
					semi[semi_check] = strtok(NULL, ">");
					if (semi[semi_check] == NULL)
					{
						semi_len = semi_check;
						break;
					}
				}// > 기준으로 명령어 모두 parse
				tmp = strtok(semi[0]," \n");	// 실제 구동명령어 parse
				token[0] = tmp;
				i =1;
				while(tmp != NULL){
					tmp = strtok(NULL, " \n");
					token[i] = tmp;
					i++;
				}

				for (k = 1; k<semi_len; k++){ // > 이후 parse 
					tmp = strtok(semi[k], " \n");
					redir[0] = tmp;	// 파일 명 추출 
					i = 1;
					while (tmp != NULL){
						tmp = strtok(NULL, " \n");
						redir[i] = tmp;
						i++;
					}
					len = i -1;      // 마지막 NULL제외
					int j = 0;
					for (j = 1; j<len; j++){
						if (strstr(redir[j], "&")){
							redir[j] = NULL;
							check = 1; //background check
						}
					}
					if ((child_pid = fork()) == 0){ // child
						// 파일명 1개
						fd = open(redir[0], O_WRONLY | O_CREAT | O_TRUNC ,0644);
						if(fd<0) exit(1);// fd error 시 exit
						close(1);
						dup(fd);
						close(fd);

						execvp(token[0], token);
						exit(1);
					}
					else if (child_pid != 0){
						if (check != 1){//background가 아니라면
							waitpid(child_pid, &status, 0);
						}
					}
				}

			}

			else if(strstr(cmd,"<")){
				strcpy(cmd_semi, cmd);
				semi[semi_check] = strtok(cmd_semi, "<");
				for (semi_check = 1;; semi_check++){
					semi[semi_check] = strtok(NULL, "<");
					if (semi[semi_check] == NULL)
					{
						semi_len = semi_check;
						break;
					}
				}// > 기준으로 명령어 모두 parse
				tmp = strtok(semi[0], " \n");    // 실제 구동명령어 parse
				token[0] = tmp;
				i = 1;
				while (tmp != NULL){
					tmp = strtok(NULL, " \n");
					token[i] = tmp;
					i++;
				}

				for (k = 1; k<semi_len; k++){ // < 이후 parse
					tmp = strtok(semi[k], " \n");
					redir[0] = tmp; // 파일 명 추출
					i = 1;
					while (tmp != NULL){
						tmp = strtok(NULL, " \n");
						redir[i] = tmp;
						i++;
					}
					len = i - 1;      // 마지막 NULL제외
					int j = 0;
					for (j = 1; j<len; j++){
						if (strstr(redir[j], "&")){
							redir[j] = NULL;
							check = 1; //background check
						}
					}
					if ((child_pid = fork()) == 0){ // child
						fd = open(redir[0], O_RDONLY | O_CREAT, 0644);
						if (fd<0) exit(1);// fd error 시 exit
						close(0);
						dup(fd);
						close(fd);

						execvp(token[0], token);
						exit(1);
					}
					else if (child_pid != 0){
						if (check != 1){//background가 아니라면
							waitpid(child_pid, &status, 0);
						}
					}
				}


			}
			else if(strstr(cmd,"|")){	// | 기준 parse 
				strcpy(cmd_pipe, cmd);
				pipearr[pipe_check] = strtok(cmd_pipe, "|");
				for (pipe_check = 1;; pipe_check++){
					pipearr[pipe_check] = strtok(NULL, "|");
					if (pipearr[pipe_check] == NULL)
					{
						pipe_len = pipe_check;
						break;
					}
				}	// | 기준으로 parse 끝
				int pipefd[2];
				pipe(pipefd);
				int pipe_pid0; int pipe_pid1; // 단일 pipe 구현
				if((pipe_pid0 = fork()) == 0){
					close(1);// stdout close
					dup(pipefd[1]); // stdout 자리로 
					close(pipefd[1]);
					close(pipefd[0]);

					tmp = strtok(pipearr[0], " \n");
					token[0] = tmp;
					i = 1;
					while (tmp != NULL){
						tmp = strtok(NULL, " \n");
						token[i] = tmp;
						i++;
					}
					execvp(token[0], token);
				}
				if((pipe_pid1 = fork()) == 0){
					close(0);//stdin close
					dup(pipefd[0]);
					close(pipefd[0]);
					close(pipefd[1]);
					tmp = strtok(pipearr[1], " \n");
					token[0] = tmp;
					i = 1;
					while(tmp != NULL){
						tmp = strtok(NULL, " \n");
						token[i] = tmp;
						i++;
					}
					execvp(token[0], token);
				}
				close(pipefd[0]); close(pipefd[1]);
				waitpid(pipe_pid0, &status, 0);
				waitpid(pipe_pid1,&status, 0);
			}

			/*
			   for(k=0;k<pipe_len;k++){ // pipe()를 통해 pipe생성 
			   pipe(pipefd+2*k);// pipefd[홀,짝] pair처럼
			   }
			   int pipefork[pipe_len];
			   for(k=0;k<pipe_len;k++){ // fork 하고 연결
			   if((pipefork[k] = fork())==0){ // child process //stdout -> 다음pipe의 stdin
			   if(k == 0){
			   close(1);//stdout close -> pipe의 입력으로 연결 , 첫번째 고려필요
			   dup(pipefd[2*k+1]);
			   close(pipefd[2*k+1]); 
			   close(pipefd[2*k]);
			   }
			   else{
			   close(0);//stdin close
			   dup(pipefd[2*k];
			   close(pipefd[2*k]);
			   close(pipefd[2*k+1]);
			   }
			   tmp = strtok(pipearr[k], " \n");// 내용 exec준비
			   token[0] = tmp;
			   i = 1;
			   while (tmp != NULL){
			   tmp = strtok(NULL, " \n");
			   token[i] = tmp;
			   i++;
			   }	
			   execvp(token[0], token);
			   close(...);
			   }
			   }
			*/

			else{ 	// pipe , redirection 아닌 명령어 
				tmp = strtok(cmd," \n");
				token[0] = tmp;
				i = 1;
				while(tmp != NULL){
					tmp = strtok(NULL," \n");
					token[i] = tmp;
					i++;
				}

				len = i-1;      // 마지막 NULL제외
				for(j=1;j<len;j++){
					if(strstr(token[j],"&")){
						token[j] = NULL;
						check =1; //background check
					}
				}
				if((child_pid = fork()) == 0){ // child 
					execvp(token[0],token);
				}
				else if(child_pid !=0){
					if(check != 1){//background가 아니라면
						waitpid(child_pid,&status,0);
					}
				}
			}
			if(cmdcheck == 1) break;	//-c이면 1회끝으로 break;
		}
	}

}
int main(int argc, char *argv[]){
	char* token[1000];
	char* tmp;
	char cmd[1000];
	int i;
	if(argc == 1){ // 인수가 없는경우
		readcmd(2,0); //cmdcheck 2 cmd while loop
	}
	else if(argc>1){	// 인수가 있는경우
		char real_cmd[1000];
		if(strcmp(argv[1] , "-c") == 0){// 그리고 option이 -c 인경우
			for(i=2;i<argc;i++)
				strcat(real_cmd,argv[i]);// command 한줄로 만들기
			//printf("%s\n",real_cmd);
		}
		readcmd(1,real_cmd);	//cmdcheck 1, -c 의 cmd만 전달
	}
}
