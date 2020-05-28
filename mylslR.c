//
// 제출년도	: 2020
// 과목명	: 시스템프로그래밍
// 과제명	: hw2 lslR
// 학번		: B411038
// 이름		: 김영수
//
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
char* def_type(struct stat buf){
	char* type;
	if (S_ISREG(buf.st_mode))	// file type = regular file 일때
		type = "-";
	else if (S_ISDIR(buf.st_mode))	// file type = directory 일때
		type = "d";
	else if (S_ISCHR(buf.st_mode))	// file type = character special file일때
		type = "c";
	else if (S_ISBLK(buf.st_mode))	// file type = block special file
		type = "b";
	else if (S_ISFIFO(buf.st_mode))	// file type = FIFO or pipe
		type = "p";
	else if (S_ISLNK(buf.st_mode))	// file type = symbolic link
		type = "l";
	else if (S_ISSOCK(buf.st_mode))	// file type = socket
		type = "s";
	else
		type = "Unkown Mode";	// 나머지 file type 일때
	return type;			// 해당 하는 file type을 반환
}
void def_permission(struct stat buf){	// permission을 출력하기위한 함수
	char permission[10];		// 1번 index 부터 사용 , 1-9 까지 USR read/write/execute GRP read/write/execute OTR read/write/execute
	if (buf.st_mode & S_IRUSR)	
		permission[1] = 'r';
	else
		permission[1] = '-';	// USR read 권한이 있으면 r 없으면 -

	if (buf.st_mode & S_IWUSR)
		permission[2] = 'w';
	else
		permission[2] = '-';	// USR write 권한이 있으면 w 없으면 -
	if (buf.st_mode & S_IXUSR)
		permission[3] = 'x';
	else
		permission[3] = '-';	// USR execute 권한이 있으면 x 없으면 -
	if (buf.st_mode & S_IRGRP)
		permission[4] = 'r';
	else
		permission[4] = '-';	// GRP read 권한이 있으면 r 없으면 -
	if (buf.st_mode & S_IWGRP)
		permission[5] = 'w';
	else
		permission[5] = '-';	// GRP write 권한이 있으면w 없으면 -
	if (buf.st_mode & S_IXGRP)
		permission[6] = 'x';
	else
		permission[6] = '-';	// GRP execute 권한이 있으면 x 없으면 -
	if (buf.st_mode & S_IROTH)
		permission[7] = 'r';
	else
		permission[7] = '-';	// Other read 권한이 있으면 r 없으면 -
	if (buf.st_mode & S_IWOTH)
		permission[8] = 'w';
	else
		permission[8] = '-';	// Other write 권한이 있으면 w 없으면 -
	if (buf.st_mode & S_IXOTH){	
		if(buf.st_mode& S_ISVTX) // other 사용자의 실행권한이 있을때
			permission[9]='t'; // sticky bit이 있다면 소문자 t로
		else
			permission[9] = 'x'; // sticky bit이 없다면 실행권한 표시
	}
	else{
		if(buf.st_mode& S_ISVTX) // 기타 사용자의 실행권한이 없을때
			permission[9]='T';	// sticky bit이 있다면 대문자 T로
		else
			permission[9] = '-'; // sticky bit이 없다면 실행권한 표시
	}
	int i;
	for (i = 1; i < 10; i++){	// 이렇게 check 한 permission을 출력
		printf("%c", permission[i]);
	}
	printf(" ");
}
void def_num_link(struct stat buf){
	printf("%d ", buf.st_nlink);	// file의 hard_link 수를 출력
}
void def_ownername(struct stat buf){
	struct passwd *pw;
	pw = getpwuid(buf.st_uid);	// file 소유주의 uid를 출력
	printf("%s ", pw->pw_name);
}
void def_ownergroup(struct stat buf){
	struct group *groupname;
	groupname = getgrgid(buf.st_gid);
	printf("%s ", groupname->gr_name);	// file 소유주의 gid를 출력
}
void def_filesize(struct stat buf, int size_len){	// file의 size를 구하기위한 함수 ,  size_len은 해당 dir에서 가장크기가 큰것
	int i=0;
	int count1 =0;	// 자릿수를 맞추기 위한 check1 과 2
	int count2 =0;
	int size = 0;
	size = buf.st_size;	//file의 size
	while(1){	// dir에서 가장 크기가 큰 size의 자리수
		size_len /=10;
		count1++;
		if(!size_len)
			break;
	}
	while(1){	// 해당 file의 크기의 자리수
		size /= 10;
		count2++;
		if(!size)
			break;
	}
	for(i;i<count1-count2;i++){ // 해당 dir 에서 가장긴길이- 해당 파일의 길이 , 공백을 맞추기 위함
		printf(" ");
	}
	printf("%d ", buf.st_size);
}
void def_rdev(struct stat buf,int size_major_len, int size_minor_len){	// device num를 구하기위한 함수, major, minor 의 device num을 출력
	int i=0;
	int count1 =0;
	int count2 =0;
	int major_size =0;
	int minor_size =0;
	major_size = major(buf.st_rdev);
	minor_size = minor(buf.st_rdev);
	while(1){	// major 길이를 이용해 출력길이 맞추기
		size_major_len /= 10;	// 해당 dir에서 가장 길이가 긴 major
		count1++;
		if(!size_major_len)
			break;
	}
	while(1){
		major_size /= 10;	// file의 major
		count2++;
		if(!major_size)
			break;
	}
	for(i;i<count1-count2;i++){	// 공백 출력을 맞추기위한 진행
		printf(" ");
	}
	printf("%d, ", major(buf.st_rdev));	// major device num을 출력
	count1=0; count2=0; i=0;
	while(1){	// minor 길이를 이용해 출력길이 맞추기
		size_minor_len /= 10;	// 해당 dir에서 가장 길이가 긴 minor 
		count1++;
		if(!size_minor_len)
			break;
	}
	while(1){
		minor_size /= 10;	// file의 minor
		count2++;
		if(!minor_size)
			break;
	}
	for(i;i<count1-count2;i++){	// 공백 출력
		printf(" ");
	}
	printf("%d ",minor(buf.st_rdev));	// minor device num을 출력
		
}
void def_time_modifi(struct stat buf){		// file의최종 수정시간을 출력
	time_t t;
	struct tm* current;
	int year; int month; int day; int hour; int min;
	char* mon_eng;
	current = localtime(&buf.st_mtime);	// localtime 함수를 통해 초단위로 st_mtime을 받아온다
	year = current->tm_year + 1900;		// 1900년 기준으로 년도가 표시가됌
	month = current->tm_mon + 1;		// month는 +1을 해주어야한다
	day = current->tm_mday;			// day
	hour = current->tm_hour;		// hour
	min = current->tm_min;			// min
	printf("%d-%02d-%02d %02d:%02d ", year, month, day, hour, min);	// 출력 형식에 맞추어 출력

}

void ls_Rl(char* current_dir, int first){	// directory를 recursive를 통해 list를 출력하는 함수
	DIR *dp;		// 현재dir의 경로를 open 해서 저장하는dp
	struct  dirent   *dirp;	// 현재dir의 경로를 read 해서 정보를 저장하는 dirp
	char   *type;		// def_type() 함수의 반환을 저장하기 위한함수
	struct  stat   buf;	// 현재 dir의 file 정보를 lstat()으로 저장하기위한 buf 
	char *dir_name[1000];	// 현재dir의 file_name을 저장하기위한 dir_name
	char* dir_type[1000];	// file_type이 directory인dir의 이름을 저장하기위한 dir_type
	int dir_type_size = 0;	// 현재 dir내부의 directory의 개수를 저장하기 위한 변수
	char dir_path[1000];	
	char file_path[1000];
	char dir_check[1000];
	int check=0;
	int i=0;
	for (i = 0; i < 1000; i++){
		dir_type[i] = malloc(sizeof(char) * 100);
	}
	dir_type[0] = ".";	//dir_type의 0 index는현재dir을 저장
	if ((dp = opendir(current_dir)) == NULL) {
		printf("ls: cannot open directory %s: %s\n",current_dir,strerror(errno)); // open error를 처리
		return ;
	}
	int total;
	total = 0;
	int dir_size = 0;
	int size_len = 0; 	// st_size 의 출력용
	int size_major_len =0;
	int size_minor_len =0;
	int name_len = 0;	// dir_name 의 길이 저장용
	while ((dirp = readdir(dp)) != NULL){	//현재 dir을 순회
		char a[1000];
		sprintf(a,"%s/%s",current_dir,dirp->d_name);	// ./path..../... 와같이 상대경로를 a에 저장
		lstat(a,&buf);	// 해당 경로의 정보를 lstat 을통해 전달받음
		if (!strncmp(dirp->d_name, ".", 1))	// 숨김파일은 continue
			continue;
		else{
			dir_name[dir_size] = dirp->d_name;	// 해당file의 이름을 저장
			if(name_len < strlen(dir_name[dir_size]))
				name_len = strlen(dir_name[dir_size]); // dir 내부중 가장 긴 길이 저장
			dir_size++;	
			total += buf.st_blocks;	// 해당 dir의 total block단위를 구하기 위함
			if(size_len < buf.st_size)
				size_len = buf.st_size;	// 가장 긴 길이로 출력맞춤

			if(S_ISCHR(buf.st_mode)){	// major num과 minor num의 출력을 맞추기위함
				if(size_major_len < major(buf.st_rdev))
					size_major_len = major(buf.st_rdev);
				if(size_minor_len < minor(buf.st_rdev))
					size_minor_len = minor(buf.st_rdev);
			}
		}
	}
	int j = 0;
	char* tmp;
	for (i = 0; i < dir_size; i++){	// linux ls -Rl의 오름차순 출력준비
		for (j = i + 1; j < dir_size; j++){
			if (strncmp(dir_name[i], dir_name[j],name_len) > 0){ //strncmp를 통해서 오름차순 정렬
				tmp = dir_name[i];
				dir_name[i]=dir_name[j];
				dir_name[j]= tmp;
			}
		}
	}
	if(first)
		printf("\n");
	printf("%s:\n", current_dir);
	printf("total %d\n", total/2 );	// 현재 경로와 total값을 출력, 이때,st_blocks는512byte가 기준이나 블럭할당은 1024byte 단위이므로 /2
	dp = opendir(current_dir);	// 현재 경로를 open
	i = 0;
	while (i < dir_size){		// 위에서 해당경로순회를 통해 size를 구한만큼 반복을 진행(dir의file수 만큼)
		sprintf(file_path, "%s/%s", current_dir, dir_name[i]);	// file_path는 dir의 file의 상대경로
		if (lstat(file_path, &buf) < 0){	// lstat()으로 file의 정보를 저장
			printf("%s\n",strerror(errno));
			return ;
		}
		if (!strncmp(dir_name[i], ".", 1)){	// 숨김파일은 continue
			continue;
		}
		else{	// 숨김 파일이 아닌경우의 진행
			type = def_type(buf);	// dir의 현재file의type을 반환받음
			if (type == "d"){	// 해당file의 type이 directory라면 이후, recursive 순회대상이므로 dir_type에 저장
				check++;	// dir 의 개수를 파악하기 위함
				sprintf(dir_check, "%s/%s", current_dir, dir_name[i]);
				strcpy(dir_type[check], dir_check);
			}
			printf("%s", type);	// 해당file의type을출력
			def_permission(buf);	// 해당file의permission을출력
			def_num_link(buf);	// 해당file의hard_link 수를 출력
			def_ownername(buf);	// 해당file의uid를출력
			def_ownergroup(buf);	// 해당file의gid를출력
			if (type == "c"){	// file의 type이character special file이라면 major device num과 minor device num을 file size대신 출력
				def_rdev(buf,size_major_len, size_minor_len);
			}
			else			// file type이 special file이 아니라면, file_size를 출력
				def_filesize(buf,size_len);
			def_time_modifi(buf);	// file의최종수정시간출력
			printf("%s", dir_name[i]);	// 해당 file의 이름을 출력
			if(S_ISLNK(buf.st_mode)){	// 해당file이 symbolic link라면link file을 출력해야한다.
				char link_buf[255];
				memset(link_buf,0x00,255);
				sprintf(dir_check,"%s/%s",current_dir,dir_name[i]);	//현재 file의 경로를 dir_check에 저장
				readlink(dir_check, link_buf, 255);			//readlink를 통해 link file name을 link_buf에반환받음
				printf(" -> %s",link_buf);	//link name을 출력
			}
			printf("\n");
		}
		i++;
	}
	for(dir_type_size = 1;dir_type_size<check+1;dir_type_size++){	//dir_type[0]은"."이므로 1번부터 현재dir의file중 directory들을 recursive
		first++;
		ls_Rl(dir_type[dir_type_size],first);	// recursive , first는 출력형식을 맞추기 위함
		//free(dir_type[dir_type_size]);
	}
	closedir(dp);
	return;

}

int main(int argc, char *argv[])
{
	if(argv[1]){	// 실행파일 뒤, 경로가 있다면
		if(argv[1]=="./"){	// 경로가 "./"라면 .으로 전달해서함수진행
			ls_Rl(".",0);
		}	
		ls_Rl(argv[1],0);	// 경로가"./"가 아니라면, 해당경로를 전달해서 함수진행
	}
	else
		ls_Rl(".",0);		// 실행파일 뒤 경로가 없다면 default로 현재경로부터 시작
	return 0;
}

