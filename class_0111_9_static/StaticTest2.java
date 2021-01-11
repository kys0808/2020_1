package class_0111_9_static;

import java.util.Arrays;

public class StaticTest2 {	// 하나의 .java file에서는 public class를 한개만 가질 수 있다!
	
	public static void main(String[] args) {
		// API 중에서 대표적인 static 메소드 : 클래스명.메소드
		
		//1. "10" -----> 10
		
		int num = Integer.parseInt("10");	// 10이라고 하는 문자열을 int 10으로 변경해주는 API
		System.out.println(num+20);		// num이 integer로 변경되었기 때문에 연산
		System.out.println("10"+20);	// 기존의 "10"은 문자열이기 때문에 연결됨
		
		//2. 10 ------>"10"		문자열이 아닌 데이터를 문자열로 변환할 때
		String str = String.valueOf(10);	//10이란 int를 String으로 변환
		System.out.println(str+20);
		
		// 또 다른 static method
		//Arrays.sort();
		//Arrats.toString();
		
	}
}
