package class_0112_5_Object_toString;

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

	@Override	// 어노테이션, @Override 의미는 현재메서드가 오버라이딩 메서드임을 알려줌
	public String getPet() {
		// TODO Auto-generated method stub
		return super.getPet() + "\t"+ color;
		// super는 부모를 가리킨다. 따라서 부모의 요소중 getPet()을 return
	}

	// 4. toString 재정의 ==> 위와 같이 getPet()보다 더 간단한 방법이다.
	@Override
	public String toString() {
		return "Cat [color=" + color + ", name=" + name + ", age=" + age + "]";
	}

	
}
