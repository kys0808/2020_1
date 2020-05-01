/*
 * 제출년도 : 2020
 * 과목명 : 시스템프로그래밍
 * 과제명 : Function Interposition
 * 학번 : B411038
 * 이름 : 김영수
*/



#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

void funcReplaced(){
	char* error;
	void (*func_cp)(); // mydynamicfunc.so 이후의 라이브러리(libfuncs.so)에서 funcReplaced를 찾았을때, 그 주소를 저장
	func_cp = dlsym(RTLD_NEXT,"funcReplaced");
	if((error = dlerror()) != NULL){
		fputs(error,stderr);
		return ;
	}
	func_cp();
	printf("In wrap_funcReplaced\n");
}

void endFunc(){
	char* error;
	void (*end_cp)(); // mydynamicfunc.so 이후의 라이브러리(libfuncs.so)에서 endFunc를 찾았을때, 그 주소를 저장
	end_cp = dlsym(RTLD_NEXT,"endFunc");
	if((error = dlerror()) != NULL){
		fputs(error,stderr);
		return ;
	}
	end_cp();
	printf("In wrap_endFunc\n");
}	
