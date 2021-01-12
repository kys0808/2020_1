package class_0112_12_인터페이스2;


interface X{
	public void a();
}

interface Y{
	public void b();
}

interface Z extends X,Y{	// 인터페이스의 다중 상속
	public void c();
}

interface A{
	//인터페이스 구성요소 4가지
	/*
	 *	1. 상수
	 *		==> public static final 자동 지정된다.
	 *
	 *	2. 추상메소드 (인터페이스의 주된 사용 목적) ==> 추상메소드로 만든 후 하위에서 강제로 사용하도록 하기위해
	 *		==> public abstract 자동 지정된다.
	 * 
	 * 	3. default 메소드
	 * 		==> 일반클래스의 인스턴스 메소드 기능과 동일
	 * 
	 * 	4. static 메소드
	 * 
	 * 
	 */
	//1.
	public static final int Num = 20;
	int SIZE =20;	// int로 선언해도 인터페이스에서는 public static final이 자동으로 지정된다.
	
	//2.
	public abstract void a();
	public void a2();		// public void로 선언해도 abstract가 자동으로 지정된다.
	
	//3.
	public default void b() {
		System.out.println("default 메소드 b()");
	}
	
	//4.
	public static void c() {
		System.out.println("static 메소드 c()");
	}
}

// 인터페이스를 사용하기 위한 임의의 클래스 도움을 받는다.
class AImpl implements A{

	@Override
	public void a() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void a2() {
		// TODO Auto-generated method stub
		
	}
	
}

public class TestMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
//		A a = new a();	// 인터페이스는 직접 객체 생성 불가 ==> 클래스를 만들어야함
//		하위클래스 이용하여 인터페이스 구성요소 사용된다.
		
		AImpl xxx = new AImpl();			// 다형성
		System.out.println(xxx.Num);
		xxx.a();
		A.c();			// 인터페이스의 static 함수는 인터페이스 이름으로 접근해야 한다!!!!!
		
	}

}
