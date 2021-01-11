package class_0111_8_클래스;

public class testmain {
	
	public static void main(String[] args) {
		
		Student s2= new Student();
		Student s = new Student("홍길동",20,"서울");	//생성하면서 인스턴스 변수 입력
		System.out.println(s.name);
		System.out.println(s.age);
		System.out.println(s.address);
		
	}
}
