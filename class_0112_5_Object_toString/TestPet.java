package class_0112_5_Object_toString;

public class TestPet {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cat c = new Cat("나비",1,"블랙");
		Dog d = new Dog("망치",1,"수컷");
		
		System.out.println("고양이 정보: "+c.getPet());
		System.out.println("강아지 정보: "+d.getPet());
		/*
		 * Object의 toString()
		 * **참조형 데이터 - 클래스 배열
		 *  인터페이스 **
		 * 1. 참조변수를 println 할때 자동으로 호출된다.
		 * 		==> 참조변수는 주소값이 저장되어있는데 print하면 콘솔(console)에 문자열로 출력시키기 위해서
		 * 			toString() 자동호출 된다.
		 * 
		 * 2. Object의 toString() 구현
		 * 
		 * 		return 클래스명@16진수;
		 * 
		 * 3. 결론은 모든 사용자 정의 클래스 toString 재정의하자
		 * 	==> 명시적인 메소드 호출없이 원하는 객체정보를 출력할 수 있다.
		 * 
		 * 4. 자식 클래스에서 toString 재정의
		 */
		System.out.println(c);
		System.out.println(d);
		
	}

}
