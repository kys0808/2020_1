package class_0113_17_제네릭스3;

import java.util.Date;

/*
 * 	제네릭스(generics)
 * 	==> <T>
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
 * 
 */

interface Product<T>{
	public abstract void setValue(T obj);
}

class Car<T> implements Product<T>{
	@Override
	public void setValue(T obj) {
		// TODO Auto-generated method stub
		System.out.println("Car.setValue"+obj);
	}
}


public class GenericTest {
	
	public static void main(String[] args) {
		
		// 1. 정수
		Car<Integer> c = new Car<Integer>();
		c.setValue(100);
		
		Car<String> c2 = new Car<String>();
		c2.setValue("현대차");
		
	}// end main
}// end class
