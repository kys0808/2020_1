package class_0112_10_추상클래스2;

public class TestPet {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cat c = new Cat("나비",1,"블랙");
		Dog d = new Dog("망치",1,"수컷");
		
		System.out.println("고양이정보1:"+c);
		c.eat();
		c.sleep();
		System.out.println("강아지정보1"+d);
		d.eat();
		d.sleep();
		
		Pet p2 = new Cat("나비", 2,"블랙");	// 추상클래스의 다형성 적용
		
	}

}
