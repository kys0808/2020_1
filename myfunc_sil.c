/*
 * 제출년도 : 2020
 * 과목명 : 시스템프로그래밍
 * 과제명 : Function Interposition
 * 학번 : B411038
 * 이름 : 김영수
*/


#include <stdio.h>

void __real_funcReplaced();
void __real_endFunc();

void __wrap_funcReplaced(){
	__real_funcReplaced();
	printf("In wrap_funcReplaced\n");
}
void __wrap_endFunc(){
	__real_endFunc();
	printf("In wrap_endFunc\n");
}

