package app5_제어문;

import java.util.*;

public class class_0111_5_제어문 {
	public static void main(String[] args) {
		/*
		 * 	문장 종류 2가지
		 * 
		 * 	1) 제어문
		 * 			- 순차문
		 * 			- 제어문
		 * 				: 분기문
		 * 					- 단일 if문
		 * 					- if else 문
		 * 					- 다중 if문
		 * 					- switch문
		 *				: 반복문
		 *					- for문
		 *					- while문
		 *					- do~while문
		 *
		 * 2) 비실행문
		 * 		-주석
		 *
		 * 
		 */
		
		// 1. 단일 if문 : 조건
		// 2. if~else문 : 조건에 따라서 실행되는 문장이 다른경우
		// 3. 다중 if문 : 조건이 여러개인 경우
			// 키보드로 입력 받기 

		/*
		System.out.println("점수입력");
		Scanner scan = new Scanner (System.in);
		int num = scan.nextInt();
		if(num >= 90) {
			System.out.println("A");
		} else if(num >= 80) {
			System.out.println("B");			
		}else if(num >= 70) {
			System.out.println("C");
		}
		else {
			System.out.println("F");
		}
		*/
		
		// 라. switch
		/*	==> 변수 값과 case 값과 비교, 일치하면 case의 문장 실행, 불일치하면 default 실행
		 * 	문법 :
		 * 		switch(변수){
		 * 			case 값1: 문장; break;
		 * 			case 값2: 문장; break;
		 * 			..
		 * 			default: 문장; break;
		 * 
		 * 
		 * 
		 */
		int xxx =10;
		switch (xxx) {
		case 5: {
			System.out.println("5");
			break;
		}
		case 10: {
			System.out.println("10");
			break;	// break문을 쓰지 않으면 아래 순차적으로 진행한다. 따라서 한 case만 다루고 싶을 때에는 break; 필요
		}
		case 15: {
			System.out.println("15");
			break;
		}
		default:
			System.out.println("default");
			break;
		}
		
		// 1. for문	: 반복 횟수 예측할 수 있을 때
		for (int i = 0; i < 5; i++) {
			System.out.println("hello" + i);
		}
		for (int i=0, j=1; i<5 && j<2; i+=2, j++) {	// 와 같은 형식도 가능하다
			System.out.println("java"+ i+"\t"+j);
		}
		
		// 2. while문 : 반복 횟수 예측이 힘들 때 주로 사용
		int k=0;
		while(true) {
			Scanner scan = new Scanner(System.in);
			System.out.println("이름 입력");
			String name = scan.nextLine();
			System.out.println("이름 : "+name);
			if(name.equalsIgnoreCase("Q"))		// equalsIgnoreCase()를 통해 예외처리
				break;	// 무한루프 탈출 조건 꼭!
		}
		
		
	}
}
