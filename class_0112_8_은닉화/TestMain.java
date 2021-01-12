package class_0112_8_은닉화;

public class TestMain {

	public static void main(String[] args) {
		/*
		 * 		은닉화(encapsulation)
		 * 
		 * 	1. 접근지정자로 은닉화
		 * 		- private	: 인스턴스 변수
		 * 		- public	: 메소드
		 * 
		 * 		==> Student 입장에서 효율적
		 * 
		 * 	2. 메소드 private
		 * 
		 * 		==> TestStudent 입장에서 효율적 (Main에서 Student 객체를 생성후 접근하고자 할 때, 사용하지 않는 메소드를 hide :복잡성 감소)
		 * 
		 */
		
		Student s = new Student();
		//s.ageCheck()와 같이 외부에서 사용하지 않는 메소드를 hide 시키기위해 ageCheck()를 private로 설정
		
		
	}

}
