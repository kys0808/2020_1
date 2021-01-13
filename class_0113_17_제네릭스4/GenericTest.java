package class_0113_17_제네릭스4;

import java.util.Arrays;
import java.util.Date;
import java.util.List;

/*
 * 	제네릭스(generics)
 * 	==> <T>, <?>, <? extends 클래스명>
 */



public class GenericTest {
	
	public static void main(String[] args) {
		
		// 1.문자열 저장 리스트
		List<String> list = Arrays.asList("홍길동","이순신","유관순");
		
		// 2. 정수 저장 리스트
		List<Integer> list2 = Arrays.asList(10,20,30);
		
		printData(list);
		printData(list2);
		
	}// end main
	
	public static void printData(List<?> obj) {
		System.out.println(obj);
	}
	
}// end class
