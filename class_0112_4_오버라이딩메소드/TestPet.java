package class_0112_4_오버라이딩메소드;

public class TestPet {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cat c = new Cat("나비",1,"블랙");
		Dog d = new Dog("망치",1,"수컷");
		
		System.out.println("고양이 정보: "+c.getPet());
		System.out.println("강아지 정보: "+d.getPet());
	}

}
