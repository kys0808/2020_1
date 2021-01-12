package class_0112_4_오버라이딩메소드;

public class Pet {
	String name;
	int age;
	
	public Pet() {
		// TODO Auto-generated constructor stub
	}
	
	public Pet(String name, int age) {
		super();
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
	
	// name과 age 동시에 반환
	public String getPet() {
		return name+"\t"+age;
	}
}
