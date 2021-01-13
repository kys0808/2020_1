package class_0113_17_제네릭스;

import java.util.Date;

/*
 * 	제네릭스(generics)
 * 	==> <T>, <?>, <? extends 클래스명>
 * 	==> 참조형만 가능 ( 기본형은 wrapper 클래스로 사용 )
 * 
 * 	기본형	----------> wrapper 클래스
 * 			 클래스 제공
 * 	byte	----------> Byte
 * 	short				Short
 * 	int					Integer
 * 	long				Long
 * 
 * 	float				Float
 * 	double				Double
 * 	
 * 	char				Character
 * 	boolean				Boolean
 */

// Box안에 여러가지 물건을 담을 수 있다. ==> Box안에 여러 데이터를 담을 수 있다.
class Box{
	
	// 데이터 갯수만큼 setValue가 추가된다.==> 오버로딩 메소드 형태로 구현
	public void setValue(String string) {
		
	}
	public void setValue(Date date) {
		
	}
	
}

public class GenericTest {
	
	public static void main(String[] args) {
	
		//	1. 문자열을 저장
		Box b = new Box();
		b.setValue("홍길동");
		
		// 2. 날짜 저장
		Box b2 = new Box();
		b2.setValue(new Date());
	}

}
