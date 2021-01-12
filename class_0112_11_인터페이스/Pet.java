package class_0112_11_인터페이스;

public abstract class Pet {
	String name;
	int age;
	
	// 애완동물의 공통적인 기능
	/*
	 * 		추상메소드(abstract Method)
	 * 
	 * 1. public abstract void 메소드명();		==> signature만 표현
	 * ==> 중괄호가 없는 abstract가 붙어있는 메소드를 추상메소드라고 한다.
	 * 2. 추상메소드를 사용하기 위해서는 class 역시 abstract가 있어야한다. ==> 추상클래스로 만들어야 한다.
	 * 3. 이 후, 자식클래스에서는 abstarct가 붙어있는 메소드는 재정의해서 사용해야 한다. 
	 * 4. 추상클래스 요소
	 * 		- 인스턴스 요소
	 * 		- 생성자
	 * 		- 일반 메소드(인스턴스 메소드)
	 * 		- 추상 메소드(abstract)
	 * 
	 * 5. 추상 클래스를 상속받은 자식에서는 반드시 추상메소드를 재정의해야한다.
	 * 	==> 목적: 자식클래스에서 특정 메소드를 강제 (통일성, 일관성)
	 * 
	 * 6. 추상 클래스는 new 불가
	 * 7. 다형성 적용 가능
	 * 
	 * ==> 여러 클래스에서 공통적인 메서드 사용하게 하자. (강제성 필요 ==> 추상클래스)
	 * 
	 */
	
	public abstract void eat();
	public abstract void sleep();
	
	
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
	

	
}
