package class_0112_2_상속적용;

public class Cat extends Pet {
	String color;

	public Cat() {
		// TODO Auto-generated constructor stub
	}
	public Cat(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	public Cat(String name, int age, String color) {
		this.name = name;
		this.age = age;
		this.color = color;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}
	
	
}
