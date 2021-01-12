package class_0112_2_상속적용;

public class TestPet {
	public static void main(String[] args) {
		
		Cat c = new Cat("나비",2,"블랙");
		Dog d = new Dog("망치",1,"수컷");
		System.out.println("고양이 이름 "+c.getName());
		System.out.println("고양이 나이 "+c.getAge());
		System.out.println("고양이 색상 "+c.getColor());
		System.out.println("강아지 이름 "+d.getName());
		System.out.println("강아지 나이 "+d.getAge());
		System.out.println("강아지 성별 "+d.getSex());
		
		
		
	}
}
