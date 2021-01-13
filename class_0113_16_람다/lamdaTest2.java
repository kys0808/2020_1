package class_0113_16_람다;

public class lamdaTest2 {

	public static void main(String[] args) {
		
		// 1. 익명 클래스
		Flyer2 f = new Flyer2() {
			
			@Override
			public void fly(int n) {
				// TODO Auto-generated method stub
				System.out.println("익명 클래스.fly");
			}
		};
		f.fly(100);
		
		// 2. 람다 표현식
		
		Flyer2 f2 = (int n)->{System.out.println("람다 표현식.fly");};
		f2.fly(100);
		
		// 3. 람다 표현식 ==> 데이터 타입 생략
		
		Flyer2 f3 = (n)->{System.out.println("람다 표현식2.fly");};
		f3.fly(300);
		
		// 4. 람다 표현식 ==> 파라미터가 1개인 경우 () 생략, 실행문이 단일 문장인 경우 {} 생략
		
		Flyer2 f4 = n-> System.out.println("람다 표현식3.fly");
		f4.fly(100);
		
	}	// end main
}	// end class
