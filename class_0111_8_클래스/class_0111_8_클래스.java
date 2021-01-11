package class_0111_8_클래스;

class Student{
	// 1. 인스턴스 변수
	/*
	 * 목적 : 데이터 저장
	 */
	String name;
	int age;
	String address;
	
	// 2. 메소드
	/*
	 *  목적 : 인스턴스 변수 관리 (수정, 조회)
	 * 
	 */
	
	
	// 3. 생성자
	/*
	 * 목적 : 인스턴스 변수 초기화
	 * 문법 :
	 * 	public 클래스명([변수, 변수2,...]){}
	 * 
	 * 특징 : 명시적으로 생성자를 만들면 기본생성자는 자동생성 안된다.
	 * 			즉, 생성자를 만들었기 때문에 기본생성자는 사용 불가
	 * 		- 오버로딩 생성자 (동일이름의 생성자 여러개 사용 가능)
	 * 			변수의 갯수 또는
	 * 			변수의 타입 또는
	 * 			변수의 순서가 반드시 달라야 한다.
	 * 
	 */
	
	public Student() {}	// 오버로딩 생성자(동일 이름의 생성자 여러개)
	public Student(String s, int s2, String s3) {
		name = s;
		age = s2;
		address = s3;
	}
	
}
