package class_0112_11_인터페이스;

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
		
		

	}

}
