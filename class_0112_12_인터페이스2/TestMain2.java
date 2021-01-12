package class_0112_12_인터페이스2;

public class TestMain2 {

	public static void main(String[] args) {
		/*
		 * 	추상 클래스와 인터페이스 비교
		 * 
		 * 	1) 추상클래스
		 * 		- public abstract class 클래스명{}
		 * 		- 구성요소 4가지
		 * 			가. 인스턴스변수, 생성자, 인스턴스메소드 ==> 일반클래스 요소
		 * 			나. 추상메소드(abstract)
		 * 
		 * 		- 특징
		 * 			: new 불가 (객체생성 불가)
		 * 			: 임의의 클래스 이용해서 추상클래스 요소 사용된다.
		 * 				==> 임의의 클래스와 추상클래스는 상속관계로서 extends 사용한다.(단일 상속만 지원)
		 * 		- 목적
		 * 			: 하위 클래스에서 특정 메소드만 사용하도록 강제 + 일반클래스의 상속 장점 제공
		 * 
		 * 
		 * 	2) 인터페이스
		 * 		- public interface 인터페이스명{}
		 * 		- 구성요소 4가지
		 * 			가. 상수, 추상메소드, default메소드, static메소드
		 * 		- 특징
		 * 			: new 불가(객체생성 불가)
		 * 			: 임의의 클래스 이용해서 인터페이스 요소 사용된다.
		 * 				==> 임의의 클래스와 인터페이스는 구현관계로서 implements 사용한다. (다중 구현 가능-- 여러개 인터페이스 연결가능)
		 * 			: 인터페이스간에 다중 상속 가능 ( extends 사용)
		 * 
		 * 		- 목적
		 * 			: 하위 클래스에서 특정 메소드만 사용하도록 강제 + 클래스들 간의 의존성 감소(decoupling)
		 * 
		 */
	}
	
}
