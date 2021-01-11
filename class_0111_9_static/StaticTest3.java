package class_0111_9_static;

import java.util.Arrays;

import static java.lang.Integer.parseInt;
import static java.lang.Integer.MIN_VALUE;
import static java.lang.Integer.MAX_VALUE;



public class StaticTest3 {	// 하나의 .java file에서는 public class를 한개만 가질 수 있다!

	
	// static 블럭 --- 임의의 작업을 초기화 할 때 사용한다.
	static {
		int num = 10;
		System.out.println(num);
		System.out.println("초기화 작업");
	}
	
	// 인스턴스 초기화 블럭 ==> 객체생성시 수행 (잘 사용하지 않음)
	{
		System.out.println("인스턴스 초기화 블럭");
		
	}
	
	public static void main(String[] args) {
		// 초기화 블럭: {}의미, 임의의 작업을 초기화 할때 사용한다.
		StaticTest3 s= new StaticTest3();
		
		// static import
		/*
		 * static 변수 및 메소드는 반드시 클래스 명을 지정해야된다.
		 * 이때, 클래스 명을 생략하는 방법이 static import가 된다.
		 * 
		 */
		
		// 1. 기존 방법
		int num = Integer.parseInt("10");
		System.out.println(num);
		
		int min = Integer.MIN_VALUE;		// static으로 된 상수 min 값 
		int max = Integer.MAX_VALUE;		// static으로 된 상수 max 값
		System.out.println(min + "\t" + max);

		// 상단에 아래와 같이 선언한 경우, 클래스 명을 생략할 수 있다
		//import static java.lang.Integer.parseInt;
		//import static java.lang.Integer.MIN_VALUE;
		//import static java.lang.Integer.MAX_VALUE;
		
		int kkk = parseInt("20");
		int kkk2 = MIN_VALUE;
		int kkk3 = MAX_VALUE;
	}
}
