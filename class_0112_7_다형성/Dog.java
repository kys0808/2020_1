package class_0112_7_다형성;

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
	public String getPet() {
		// TODO Auto-generated method stub
		return super.getPet() + "\t" + sex;
	}

	@Override
	public String toString() {
		return "Dog [sex=" + sex + ", name=" + name + ", age=" + age + "]";
	}
	
	
}
