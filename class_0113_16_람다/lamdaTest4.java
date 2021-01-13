package class_0113_16_람다;

public class lamdaTest4 {
	public static void main(String[] args) {
		// 1. 익명 클래스
		Flyer4 f = new Flyer4() {
			@Override
			public int fly(int n, int n2) {
				// TODO Auto-generated method stub
				return n+n2;
			}
		};
		int result = f.fly(10, 20);
		System.out.println("1. 익명 클래스 결과값 :"+result);
		
		// 2. 람다표현식
		Flyer4 f2 = (int n, int n2)->{return n+n2;};
		int result2 = f2.fly(20, 30);
		System.out.println("2. 람다 표현식 결과값 :"+result2);
		
		// 3. 람다표현식 -- 파라미터 타입 생략
		Flyer4 f3 = (n,n2)->{return n+n2;};
		
		// 4. 람다표현식 -- 리턴 타입 생략, 중괄호 생략
		Flyer4 f4 = (n,n2)->n+n2;
		int result3 = f4.fly(100, 200);
		System.out.println("3. 람다 표현식 결과값 :"+result3);
		
	}	//end main
}	//end class
