package class_0112_3_부모부터;

public class Pet {
	public Pet() {
		super(); 	
		// 기본생성자 호출 (자동 삽입) -- 자식은 기본적으로 생성자를 호출할 때 기본생성자를 호출한다.
		System.out.println("Pet클래스 생성자");
	}
	
	public Pet(int num) {
		super(); 
		// 항상 생성자 첫 라인에는 super();가 명시되지 않으면 삽입된다.
		// 부모의 속성인 것은 super(인자,인자..);로 부모클래스에서 초기화하여 사용한다.
		System.out.println("Pet2클래스 생성자");
	}
	
}
