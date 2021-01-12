package class_0112_2_상속적용;

// Dog과 Cat의 공통적인 속성 및 동작을 정의 하기 위한 class
public class Pet {
	// 공통적인 속성
	// 부모의 private 속성은 상속되지 않는다.
	String name;
	int age;
	
	public Pet() {
		// TODO Auto-generated constructor stub
	}
	
	public Pet(String name, int age) {
		this.name = name;
		this.age = age;
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
	public void setAge(int age) {
		this.age = age;
	}
	
	
}
