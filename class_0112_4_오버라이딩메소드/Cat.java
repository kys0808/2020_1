package class_0112_4_오버라이딩메소드;

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

	
}
