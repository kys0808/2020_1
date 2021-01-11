package project_3_variable;

public class variable_3 {
	public static void main(String[] args) {	//프로그램의 시작점 역할 (starting point) ==> 반드시 이 구조를 가져야 한다.
		/*
		 *	변수
		 *	1. 목적 : 데이터 저장
		 *	2. 종류 :
		 *			- 기본형 변수	: 기본형 데이터를 저장하는 변수
		 *				==> 변수에 가면 실제 기본데이터 저장되어 있다.
		 *
		 *			- 참조형 변수	: 참조형 데이터를 저장하는 변수 (클래스, 배열, 인터페이스) ==> 주소값이 저장되고 크기는 항상 4byte이다
		 *				==> 변수에 가면 실제 데이터가 저장된 주소값이 저장되어 있다.
		 *
		 *	3. 문법 (순서)
		 *		가. 변수 선언	: 메모리에 데이터를 저장할 영역을 만들고 영역의 이름을 지정
		 *				- ex) 데이터형 변수명 ; // int num; String name;
		 *		나. 변수 초기화
		 *				- ex) 변수명 = 값; // num = 3; name = "영수";
		 *
		 *	4. 선언위치에 따른 변수 3가지 종류(***)
		 *		가. 로컬 변수 
		 *		- 메서드안에서 선언된 변수
		 *		- 생성 : 메소드 호출할 때 ~ 메소드 작업 끝나면 제거
		 *		- stack 메모리에 저장
		 *		- 사용전에 반드시 초기화 해야한다.
		 *
		 *
		 *		나. 인스턴스 변수 
		 *		- 메서드 밖에서 선언된 변수
		 *		- 객체생성(new) ~ 객체 소멸시 제거
		 *		- heap 메모리에 저장
		 *		- 자동 초기화 (정수 : 0, 실수: 0.0, 논리: false, 참조형: null)
		 *
		 *
		 *
		 *		다. 클래스 변수(static 변수) 
		 *		- 메서드 밖에서 선언된 변수 + static
		 *		- 프로그램 실행시 ~ 프로그램 종료 (가장 빨리 만들어 지면서 가장 늦게 제거)
		 *		- method area에 저장
		 *		- 자동 초기화 (정수 : 0, 실수: 0.0, 논리: false, 참조형: null)
		 *
		 *
		 */
			int num=0;	// 로컬 변수 - 초기화가 반드시 되어야 한다.
			System.out.println(num);
			
		/*
		 * 데이터 형변환
		 * ==> 데이터 종류가 변경 가능
		 * 
		 * 가. 묵시적 형변환 (자동 형변환)
		 * 		a. byte > short > int > long > float > double
		 *		b. char > int
		 *		c. int보다 작은 데이터형의 연산 결과는 int로 변환
		 *			예>
		 *			short s = 10;
		 *			short s2 = 20;
		 *			short result = s+s2;	// 에러 발생 (각각은 short지만, 연산 결과는 int형으로 나온다.)
		 *			int result = s+s2;		// 에러 발생 안한다.
		 *		d. 작은 타입과 큰타입 연산결과는 큰타입으로 변환
		 *
		 * 나. 명시적 형변환 (강제 형변환)
		 * 		==> (형변환)변수
		 * 
		 * ===> 데이터 형변환은 기본형 뿐만 아니라 참조형도 가능하다.(즉, class도 형변환이 가능하다)
		 * 
		 * 
		 */
		// 예1>
		short s = 10;
		short s2 = 20;
		int result = s+s2;	// short result로 선언하면 오류 
		System.out.println(result);
		
		// 강제 형변환
		short result2 = (short)(s+s2);
			
		// 예2>
		char c = 'A';
		int c2 = c;
		System.out.println(c2);		// 'A' : 65 , 'a' :97
		System.out.println(c+1);
		System.out.println(c>66);
	}
}
