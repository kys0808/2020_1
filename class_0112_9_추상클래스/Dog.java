package class_0112_9_추상클래스;

public class Dog extends Pet {
	String sex;
	
	public Dog() {
		// TODO Auto-generated constructor stub
	}

	public Dog(String name, int age) {
		super(name, age);
		// TODO Auto-generated constructor stub
	}
	public Dog(String name, int age, String sex) {
		this.name = name;
		this.age = age;
		this.sex = sex;
	}

	public String getSex() {
		return sex;
	}

	public void setSex(String sex) {
		this.sex = sex;
	}

	@Override
	public String toString() {
		return "Dog [sex=" + sex + ", name=" + name + ", age=" + age + "]";
	}
	//Dog 클래스는 재정의하지 않고 나름 메소드를 추가
	public void dog_eat() {
		System.out.println("Dog.dog_eat");
	}
	public void dog_sleep() {
		System.out.println("Dog.dog_sleep");
	}
	
}
