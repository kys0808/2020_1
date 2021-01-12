package class_0112_9_추상클래스;

public class Cat extends Pet {
	String color;

	public Cat() {
		// TODO Auto-generated constructor stub
	}


	public Cat(String name, int age) {
		super(name, age);
		// TODO Auto-generated constructor stub
	}

	public Cat(String name, int age, String color) {
		super(name, age);
		this.color = color;
		// TODO Auto-generated constructor stub
	}

	public String getColor() {
		return color;
	}


	public void setColor(String color) {
		this.color = color;
	}

	// 4. toString 재정의 ==> 위와 같이 getPet()보다 더 간단한 방법이다.
	@Override
	public String toString() {
		return "Cat [color=" + color + ", name=" + name + ", age=" + age + "]";
	}
	
	@Override
	public void eat() {
		// TODO Auto-generated method stub
		System.out.println("Cat.eat");
	}


	@Override
	public void sleep() {
		// TODO Auto-generated method stub
		System.out.println("Cat.sleep");
	}

	
}
