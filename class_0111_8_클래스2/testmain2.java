package class_0111_8_클래스2;

public class testmain2 {
	
	public static void main(String[] args) {
		
		Student s= new Student();
		
		//setter 메소드	==> 검증할 수 있다.
		s.setName("홍길동");
		s.setAge(20);
		s.setAddress("서울");
		//getter 메소드	==> 검증할 수 있다.
		System.out.println(s.getName());
		System.out.println(s.getAge());
		System.out.println(s.getAddress());
		
		/*
		 * s.name , s.age, s.address와 같이 
		 * 변수를 직접 접근해도 아무 문제 없었다. 왜 메소드가 필요할까?
		 * ==> 변수를 직접 접근하면 age = 2000과 같이 논리적으로 불가능한 선언까지 가능
		 * 따라서 메소드를 통해 검증작업을 통해 입력할 수 있도록 한다.
		 * 우선, 인스턴스 변수의 접근제어자 private 선언
		 * 
		 */
		
	}
}
