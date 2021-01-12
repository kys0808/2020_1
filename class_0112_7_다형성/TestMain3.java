package class_0112_7_다형성;

public class TestMain3 {

	public static void main(String[] args) {
		// 1. 다형성 미적용
		Cat c1 = new Cat("나비1",2,"블랙");
		Cat c2 = new Cat("나비2",2,"블랙");
		Cat c3 = new Cat("나비3",2,"블랙");
		Dog d1 = new Dog("망치1",1,"수컷");
		Dog d2 = new Dog("망치2",1,"수컷");
		
		
		// 배열로 관리
		Cat[] cats = {	new Cat("나비1",2,"블랙"),
						new Cat("나비2",2,"블랙"),
						new Cat("나비3",2,"블랙")};
		Dog[] dogs = {	new Dog("망치1",1,"수컷"),
						new Dog("망치2",1,"수컷")};
		
		
		// 2. 다형성 적용 
		//	==> 하나의 변수로 모든 애완동물 참조 가능 (Pet으로 Dog와 Cat을 관리할 수 있다.)
		//	==> 데이터 관리면에서 효율적이다.
		
		// 가. 배열사용 - 다형성의 대표적인 샘플 (상위 타입 배열로 하위 타입 배열을 관리할 수 있다. 따라서 변수 하나로 서로 다른 타입을 관리할 수 있다)
		// 부모클래스 타입 = new 자식클래스 타입 --> 부모-자식 관계에서만 가능하다
		Pet[] pets = {	new Cat("나비1",2,"블랙"),
						new Cat("나비2",2,"블랙"),
						new Cat("나비3",2,"블랙"),
						new Dog("망치1",1,"수컷"),
						new Dog("망치2",1,"수컷")};

		for(Pet pet : pets) {
			System.out.println(pet);
		}
		
		// 다형성 확장 - Object는 모든 객체의 상위이기때문에 데이터의 구분 없이 배열로 저장할 수 있다.
		Object[] obj = {"홍길동", 20, new Date()};
			
		//나. 메소드 파라미터 - 다형성의 대표적인 샘플
		setData(10);
		setData(3.14);
		setData("홍길동");
		
	}
	// 다형성을 적용하지 못하면 아래와 같이 오버로딩을 적용해야 한다.
	/*
	public static void setData(String obj) {
		
	}
	public static void setData(int obj) {
		
	}
	public static void setData(double obj) {
		
	}
	*/
	// 다형성을 적용하면 아래와 같이 하나로 정의할 수 있다.
	public static void setData(Object obj) {	// 다형성 적용 (인자의 타입을 Object를 씀으로써)
		
	}
	
}
