package class_0112_9_추상클래스;

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

	@Override
	public String toString() {
		return "Pet [name=" + name + ", age=" + age + "]";
	}
	
	// 애완동물의 공통적인 기능
	public void eat() {
		System.out.println("Pet.eat");
	}
	public void sleep() {
		System.out.println("Pet.sleep");
	}
	
}
