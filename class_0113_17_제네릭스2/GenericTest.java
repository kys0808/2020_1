package class_0113_17_제네릭스2;

import java.util.Date;

/*
 * 	제네릭스(generics)
 * 	==> <T>
 * 
 * 
 */


// Box안에 여러가지 물건을 담을 수 있다. ==> Box안에 여러 데이터를 담을 수 있다.

// Object --> T 로 변경. T는 Box 클래스를 생성할 때 구체적인 타입으로 변경된다.
class Box<T>{
	
//	Object obj;
	T obj
	public void setValue(T obj) {
		this.obj = obj;
	}
	
	public T getValue() {
		return obj;
	}
	
}

public class GenericTest {
	
	public static void main(String[] args) {
	
		//	1. 문자열을 저장
		Box<String> b = new Box<String>();
		b.setValue("홍길동");
		// 가. 잘못된 데이터가 저장된 사실을 개발단계인 컴파일시점이 아닌 실제로 실행되는 런타임 시점에 확인할 수 있다.
		// ==> Generic을 이용하면 컴파일 시점에 잘못된 데이터가 저장된 사실을 확인할 수 있다.
//		b.setValue(10);	
		
		// 나. 반드시 형변환 필요
		// ==> Generic을 이용하면 형변환 불필요
//		String str = (String)b.getValue();
		String str = b.getValue();
		System.out.println("1. "+str);
		
		// 2. 날짜 저장
		Box<Date> b2 = new Box<Date>();
		b2.setValue(new Date());
		Date d = (Date)b2.getValue();
		System.out.println("2. "+d);
		
	}// end main
}// end class
