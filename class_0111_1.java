package project_1;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		// 콘솔에 출력방법
		
		// 1. 새로운 줄 생성하면서 출력
		System.out.println("홍길동");
		System.out.println("유관순");
		
		/*
		 * 한줄 복사 	: ctrl + alt + 화살표
		 * 한줄 삭제 	: ctrl + d
		 * 실행		: ctrl + F11
		 * 자동 완성	: ctrl + space
		 * 
		 */
		
		//2. 한 라인에 출력
		System.out.print("이순신");
		System.out.print("강감찬");
		System.out.println();
		
		//3. 포맷 출력
		/*
		 *  %s 문자열 / %d 정수 / %f 실수 / %c 문자 / %b 논리 값
		 * 
		 */
		System.out.printf("이름 : %s, 나이 : %d, 키:%.1f, 성별:%c,  결혼:%b", "홍길동", 27, 177.1, '남', true);
	}
}