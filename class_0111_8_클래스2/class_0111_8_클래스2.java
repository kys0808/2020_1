package class_0111_8_클래스2;

class Student{
	// 1. 인스턴스 변수
	
	/*
	 * 접근지정자(접근 제어자 : access modifier)
	 * ==> 외부클래스에서 자신 접근 제약지정
	 * 
	 * public				: 제약이 없다. 누구나 접근 가능
	 * protected
	 * 			(default)
	 * private
	 * 
	 */
	private String name;
	private int age;
	private String address;
	
	/*
	 * 생성자, 메소드 만드는 법
	 * 	가. 인스턴스 변수 선언
	 * 	나. 마우스 우클릭 > Source > generate
	 */
	
	// 2. 기본 생성자
	public Student() {
		// TODO Auto-generated constructor stub
	}
	
	// 2. 생성자
	
	/*
	 * this?
	 * 1. 객체생성된 후
	 * 		heap 메모리에 올라간 자신을 참조하는 키워드
	 * 
	 */
	
	public Student(String name, int age, String address) {
		this.name = name;
		this.age = age;
		this.address = address;
	}
	// 3. 메소드 값 변경 및 조회
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		if(age>100) {	// setter를 이용한 유효성 체크
			System.out.println("age 잘못설정");
		}else {
		this.age = age;
		}
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}
	
}