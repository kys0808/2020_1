package app5_제어문;

import java.util.Arrays;
import java.util.List;


public class class_0111_6_배열 {
	public static void main(String[] args) {
		/*
		 * 변수(variable)
		 * 1. 값 하나만 저장할 수 있다. ==> 데이터가 많아지면 자연스럽게 변수도 많아진다 --> 관리가 어려워 진다.
		 * 2. 사용 방법
		 * 		가. 변수선언
		 * 		나. 초기화
		 * 
		 * 배열
		 * 1. 여러 데이터를 변수(배열명) 하나로 동일한 데이터만을 관리할 수 있다.
		 * 2. 사용 방법
		 * 		가. 배열선언
		 * 			예> 
		 * 				int n;		// 기본형 변수
		 * 				int [] num;	// 참조형 변수, 변수에 가면 주솟값
		 * 
		 * 		나. 배열생성(new를 이용해 만든다)
		 * 			num = new int[크기];
		 * 
		 * 			
		 * 		다. 초기화
		 * 3. 참조형 데이터 : 클래스, 배열, 인터페이스 ==> 사용하기 위해서는 무조건 생성부터 해야한다. (new를 이용)
		 * 
		 * 4. 배열 사용방법 3가지
		 *		가. new 이용
		 *		나. 초기값 이용 (new 없이)
		 * 			예> 데이터형 [] 배열명 = {값, 값2 };
		 * 		다. 가+나 방법
		 */
		
		// 가. new 이용
		int [] num;			// ==> main이라는 메소드 안에서 생성됐기 때문에 로컬변수이다. stack영역에서 생성
		num = new int[3];	// new를 이용, 인스턴스와 관련, heap메모리에서 생성
		
		System.out.println(num[0]);
		System.out.println(num[1]);
		System.out.println(num[2]);
		num[0] = 10;
		num[1] = 20;
		num[2] = 30;
		
		for(int i=0;i<num.length;i++) {
			System.out.println(">>>"+num[i]);
		}
		// for each문 : 조건식이 없다. 따라서 예외발생 가능성 없다.
		for(int i : num) {	// num배열에서 꺼내와 i에 대입, num의 길이 만큼 사용한다.
			System.out.println("###"+i);
		}
		
		// 나. 초기값 이용 (선언 후 초기화 불가하다)
		int [] num2 = {100,200, 300};	// 선언과 동시에 한번에 초기화 해야한다.
		
		for(int i : num2) {
			System.out.println(i);
		}
		
		// 다. 가+나 방법 혼합
		int []num3 = new int[] {1000,2000,3000};	// 주의, new int [10]과 같이 크기를 지정하면 안된다.
		for(int i : num3) {
			System.out.println(i);
		}
		
		
		/*
		 *	2차원 배열 
		 */
		int [][] num4 = {{100,200},{400,500,600}};
		System.out.println(num4.length);
		System.out.println(num4[0].length);
		System.out.println(num4[1].length);
		
		for(int[] is : num4) {
			for(int n : is) {
				System.out.print(n);
			}
			System.out.println();
		}
		
		/*
		 * 	java.util.Arrays 유틸리티 클래스 - 배열과 관련된 유용한 클래스
		 * 
		 * 
		 */
		String [] names = {"Java", "SQL", "Oracle", "Angular"};
		
		// 1. 정렬
		Arrays.sort(names);
		for(String s : names) {
			System.out.println(s);
		}
		
		// 2. 배열값을 문자열로 출력
		System.out.println("2. 배열값을 한꺼번에 출력:" +Arrays.toString(names));
		
		// 3. java.util.List 쉽게 생성하기 (asList)
		List<String> list = Arrays.asList("홍길동","이순신","유관순");
		System.out.println(list);
		
		
	}
}
