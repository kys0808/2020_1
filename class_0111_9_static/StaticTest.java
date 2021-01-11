package class_0111_9_static;

class Counter{
	int num;
	static int count;	// count는 프로그램 시작될때 만들어지고 프로그램 종료할때 삭제된다. 그리고, 한번 만들어지면 쭈욱 사용가능 / 한번만 생성, 누적용, 클래스.count로 접근, new 무관
	public Counter() {
		num++;
		count++;
	}
	
	public static int getCount() {	// method를 static으로 만드는 목적 - 1. new 없이 사용하기 위해서 2. 싱글톤 객체로 만들기 위해 : 단 하나의 인스턴스만 생성패턴
		return count;
		// return num; 				// 오류나는 이유? num보다 getCount()가 먼저 만들어지기 때문에 num에 접근할 수 없다.
									// this역시 사용 불가하다 왜? this는 인스턴스에서 접근하기 위함이기 때문이다. 인스턴스는 static단계에서 생성되지 않는다. new를 통해 생성
	}
	public int getNum() {
		// ==> 인스턴스 메소드 : this, 인스턴스 변수, static 변수 모두 사용 가능하다.
		
		System.out.println(this);
		//return count;
		return num;
	}
}

public class StaticTest {	// 하나의 .java file에서는 public class를 한개만 가질 수 있다!
	
	public static void main(String[] args) {
		//Counter 클래스 생성횟수 출력
		
		System.out.println(Counter.count);		//	객체 new생성 하지 않아도 생성이 되어있다. 왜? 프로그램 생성할때 만들어지기 때문
		System.out.println(Counter.getCount());	//	객체 new 생성하지 않아도 메소드 사용가능
		
		Counter c = new Counter();
		System.out.println(c.num);
		System.out.println(c.count);
		
		c = new Counter();	
		// 새로운 인스턴스가 만들어졌기 때문에, 인스턴스 변수는 누적으로 사용되지 않는다.
		// 이전 객체는 가리키지 않기 때문에 소멸된다.
		System.out.println(c.num);
		System.out.println(c.count);
		
	}
}
