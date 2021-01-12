package class_0112_8_은닉화;

public class Student {
	// 1. 은닉화(Student) : 직접 접근하지 못하게 변수를 private 설정==> 올바른 데이터 설정 목적
	/*
	 * 
	 * 
	 */
	private String name;
	private int age;
	private String address;
	
	public Student() {
		// TODO Auto-generated constructor stub
	}
	public Student(String name, int age, String address) {
		this.name = name;
		this.age = age;
		this.address = address;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	
	//검증 메소드 -- private로 설정하면 외부에서 접근 불가하므로 복잡성을 감소시킬수 있다.
	private boolean ageCheck(int age) {
		boolean result = false;
		if(age>100) {
			result = true;
		}
		return result;
	}
	
	public void setAge(int age) {
		if(ageCheck(age)) {
			System.out.println("age 잘못설정");
		}
		else {
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
