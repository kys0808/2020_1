package class_0112_15_익명클래스;


	// 인터페이스를 사용하는 방식 2가지
	/*
	 * 1) 중첩클래스 (nested class)
	 * 		Class Outer{
	 * 		..
	 * 		..
	 * 		..
	 * 		class Inner{
	 * 
	 * 			} //end Inner
	 * 
	 * 		}// end class
	 * 
	 * 
	 * 2) 익명 클래스 (anonymous class)
	 * 	==> 이름이 없는 클래스
	 * 	==> 인터페이스 사용시 주로 익명클래스 사용됨. (가독성 높다)
	 * 	==> 안드로이드 개발 시 주로 사용.
	 */

interface Flyer{
	public abstract void fly();
}

//1. Bird 이름있는 클래스
class Bird implements Flyer{
	@Override
	public void fly() {
		System.out.println("Bird.fly");
	}
}

public class 익명클래스 {
	
	public static void main(String[] args) {
		//1. Bird 생성 사용
		Flyer f = new Bird();
		f.fly();
		
		//2. 익명 클래스	==> 가독성이 높다 , 기존의 명시된 클래스와 같은경우에는 해당 메소드가 무엇이 있는지 확인하고 와야하는데
		//					익명클래스는 한번에 보여주기때문에 가독성에 좋다
		
		/*
		 * 	인터페이스명 변수명 = new 인터페이스명(){
		 * 		// 메소드 재정의
		 * 	};
		 */
		
		Flyer f2 = new Flyer(){
			@Override
			public void fly() {
				// TODO Auto-generated method stub
				System.out.println("익명클래스.fly");
			}
		};
		f2.fly();
		
		// 이클립스 자동완성 기능
		Flyer f3 = new Flyer() {
			
			@Override
			public void fly() {
				// TODO Auto-generated method stub
				System.out.println("익명클래스2.fly");
			}
		};
		f3.fly();
		
		
	}// end main
}	// end class
