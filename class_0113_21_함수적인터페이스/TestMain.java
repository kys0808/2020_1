package class_0113_21_함수적인터페이스;

public class TestMain {

	/*
	 * 	함수적 인터페이스 API
	 * 
	 * 	1. JDK 1.8 지원
	 * 	2. java.util.function 패키지 포함되고 모두 interface로 구성됨
	 * 		==> interface 사용하려면
	 * 			a. 이름있는 클래스
	 * 			b. 익명 클래스
	 * 			c. 람다 함수(****)
	 * 
	 * 		종류 5가지 (함수적 인터페이스)
	 * 		가.	Consumer
	 * 			==> 파라미터 있고 리턴값 없는 경우
	 * 		나.	Supplier
	 * 			==> 파라미터 없고 리턴값 있는 경우
	 * 		다.	Function
	 * 			==> 파라미터 있고 리턴값 있는 경우
	 * 		라.	Operator
	 * 			==> 파라미터 있고 리턴값 있는 경우
	 * 		마.	Predicate
	 * 			==> 파라미터 있고 리턴값(boolean) 있는 경우
	 * 
	 * 
	 * 		===> 공통적으로 추상 메소드가 선언되어 있다.
	 * 		===> 기능적으로 모든 메소드는 4가지 형태로 되어있다.
	 * 			가. 파라미터 없고 리턴값 없는 경우
	 * 			나. 파라미터 있고 리턴값 없는 경우
	 * 			다. 파라미터 없고 리턴값 있는 경우
	 * 			라. 파라미터 있고 리턴값 있는 경우
	 * 
	 * 		===> 위 4가지 기능을 구현하고자 한다면
	 * 			직접 클래스로 구현하지 말고 상위의 함수적 인터페이스를 사용하자.	(******)
	 * 
	 */
	
}
