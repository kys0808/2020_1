package class_0113_16_람다;

public class lamdaTest3 {
	public static void main(String[] args) {
		// 1. 익명 클래스
		Flyer3 f = new Flyer3() {
			@Override
			public int fly() {
				// TODO Auto-generated method stub
				return 9999;
			}
		};
		
		int result = f.fly();
		System.out.println("1. 익명클래스 결과값 : "+result);
		
		Flyer3 f2 = ()->{ 
			System.out.println("람다표현식.fly");
			return 9999;
		};
		int result2 = f2.fly();
		System.out.println("2. 람다표현식 결과값: "+result2);
		
		// 3.람다표현식 ==> 실행문자이 return만 있는 경우에는 {}; 와 return 키워드 생략
		Flyer3 f3 = ()-> 7777;
		int result3 = f3.fly();
		System.out.println("3. 람다표현식 결과값: "+result3);
		
	}	//end main
}	//end class
