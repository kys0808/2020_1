package com_app4_연산자;

public class 연산자01_산술연산자 {
	public static void main(String[] args) {
		//	1. 산술 연산자
		
		int num = 10;
		int num2 = 3;
		
		System.out.println(num+num2);
		System.out.println(num-num2);
		System.out.println(num*num2);
		System.out.println(num/num2);
		System.out.println(num%num2);
		
		// 2. 비교 연산자
		
		System.out.println(num>num2);
		System.out.println(num>=num2);
		System.out.println(num<num2);
		System.out.println(num<=num2);
		System.out.println(num==num2);
		System.out.println(num!=num2);
		
		// 3. 대입 연산자
		int num3 = 10;
		int result = num3;	// 대입 연산자
		
		result += num3;
		result -= num3;
		result *= num3;
		result /= num3;
		result %= num3;
						
		// 4. 논리 연산자 ( &&, ||, ! )
		
		System.out.println(true && true);
		System.out.println(false && true);
		System.out.println(true && false);
		System.out.println(false && false);
		System.out.println("//////////////////");
		System.out.println(true || true);
		System.out.println(false || true);
		System.out.println(true || false);
		System.out.println(false || false);
		System.out.println("//////////////////");
		System.out.println(!true);
		System.out.println(!false);

		System.out.println("//////////////////");
		// 문제 : num 값이 15보다 크고, num2값이 30보다 작나?
		int num4 = 10;
		int num5 = 10;
		System.out.println( (num4>15)&&(num5<30));
		
		System.out.println("//////////////////");
		// 문제2 : num값이 15보다 크거나 num2값이 30보다 작나?
		System.out.println((num4>15)||(num5 <30));
		
		/*
		 *  실행결과가 논리값 반환하는 연산자?
		 *  가. 비교연산자
		 *  나. 논리연산자
		 * 	다. instanceof 연산자 : 실제 생성된 인스턴스타입 체크
		 * 
		 */
		// instanceof 연산자 예시
		System.out.println("//////////////////");
		String name = "홍길동";
		System.out.println(name instanceof String);
		
		
		//5. 증감연산자 ==> 증가 연산자, 감소 연산자
		/*	1) 증가 연산자
		 * 		1씩 증가
		 * 		++
		 * 	예>
		 * 		++num; : 전치 연산자, 
		 * 		num++; : 후치 연산자
		 * 
		 * 	2) 감소 연산자
		 * 		1씩 감소
		 * 		--
		 * 	예> 
		 * 		--num;
		 * 		num--;
		 * 
		 *	주의할 점 ==> 다른 연산자와 같이 사용할 때 실행결과가 달라질 수 있다.
		 *
		 */
		int num6 = 10;
		int result6 = ++num6;	//증가 먼저
		System.out.println(result6 + "\t"+num6);	// 따라서 11,11
		
		int num7 = 10;
		int result7 = num7++;	// 증가를 나중에		// 따라서 10,11
		System.out.println(result7+"\t"+num7);
		
		System.out.println(getnum());
		System.out.println(getnum2());
		
		//6. 3항 연산자 (조건식에 따라 참,거짓 값 반환)
		/*
		 * 문법:
		 * 		변수명 = (조건식)?참:거짓;
		 * 
		 */
		int result8 = (300>200)?100:200;
		System.out.println(result8);
		
	}
	public static int getnum() {
		int num = 9;
		return ++num;	// 먼저 증가하고 반환
	}
	
	public static int getnum2() {
		int num = 9;
		return num++;	// 먼저 반환하고 증가
	}
	
}
