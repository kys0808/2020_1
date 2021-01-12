package class_0112_7_다형성;

public class TestMain4 {
	
	public static void main(String[] args) {
		Pet[] pets = {	new Cat("나비1",2,"블랙"),
				new Cat("나비2",2,"블랙"),
				new Cat("나비3",2,"블랙"),
				new Dog("망치1",1,"수컷"),
				new Dog("망치2",1,"수컷")};

		// 1. 모든 애완동물 출력
		for(Pet pet : pets) {
			System.out.println(pet);
		}
		
		// 2. 고양이만 출력 ==> 고양이 타입인지 체크, instanceof로 check
		for(Pet pet: pets) {
			if(pet instanceof Cat) {
				System.out.println("고양이 정보만 출력 :"+ pet);
			}
		}
		// 3. 고양이의 정보중에서 색상만 출력
		for(Pet pet : pets) {
			if(pet instanceof Cat) {
				// Pet을 Cat으로 형변환이 필요하다 -- Pet에는 getColor가 없다
				// 클래스도 형변환이 가능하다 -- 단, 상속관계에서 가능하다
				Cat cat = (Cat) pet;
				System.out.println("고양이 색상만 출력: "+ cat.getColor());
			}
		}
	}

}
