package class_0112_3_부모부터;

public class TestPet {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cat c = new Cat();
		
		/*
		 * 생성자 호출 형태
		 * 1. 다른 클래스에서 객체생성시
		 * 		new 클래스명();
		 * 
		 * 2. 자식클래스에서 부모생성자 호출
		 * 	( 자식클래스의 생성자 첫라인에 자동 삽입 )
		 * 		super();
		 * 		명시적으로 지정할 시 반드시 첫라인에 사용해야됌 -> 만약 super()보다 먼저 다른 코드가 있다면 오류
		 * 		즉, super();를 적을 때에는 생성자의 가장 첫 줄에 있어야 한다.
		 * 
		 * 3. 같은 클래스의 특정생성자에서 오버로딩생성자 호출
		 * 		this();
		 */
	}
}
