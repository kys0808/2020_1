package class_0112_7_다형성;

public class TestMain2 {

	public static void main(String[] args) {
		// 1. 다형성 미적용
		Cat c = new Cat("나비",2,"블랙");
		Dog d = new Dog("망치",1,"수컷");
		
		
		// 2. 다형성 적용 ==> 하나의 변수로 모든 애완동물 참조 가능
		// 부모클래스 타입 = new 자식클래스 타입 --> 부모-자식 관계에서만 가능하다
		Pet pet = new Cat("나비",2,"블랙");
		System.out.println("고양이정보 "+pet);
			pet = new Dog("망치",1,"수컷");
		System.out.println("강아지정보 "+pet);
	}

}
