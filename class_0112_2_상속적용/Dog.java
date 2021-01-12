package class_0112_2_상속적용;

public class Dog extends Pet {	// 단일 상속만 지원하기 때문에 Dog의 부모는 Pet만 가능하다.
	String sex;	// 고유한 속성
	
	public Dog() {
		
	}
	
	public Dog(String name, int age) {
		this.name = name;
		this.age = age;
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
	
}
