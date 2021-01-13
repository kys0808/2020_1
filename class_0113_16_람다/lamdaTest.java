package class_0113_16_람다;

public class lamdaTest {
	public static void main(String[] args) {
		
		// 1. 익명 클래스
		Flyer f = new Flyer() {
			
			@Override
			public void fly() {
				// TODO Auto-generated method stub
				System.out.println("익명 클래스.fly");
			}
		};
		
		f.fly();
		
		// 2. 람다 표현식		()-> == public void fly()를 의미한다.
		Flyer f2 = ()-> { System.out.println("람다 표현식.fly");
		};
		
		f2.fly();
		
		// 2. 람다 표현식 ==> 단일 문장인 경우에는 {} 생략 가능
		Flyer f3 = ()-> System.out.println("람다 표현식2.fly");
		f3.fly();
		
	}
}
