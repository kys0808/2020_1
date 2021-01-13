package class_0113_18_컬렉션API;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class ListTest3 {

	public static void main(String[] args) {

		// Arrays.asList() 메소드 ==> 기존 리스트와 다르게 배열속성을 갖는다. 그래서 수정이 안된다.
		List<String> list = Arrays.asList("홍길동", "이순신");
		list.add("유관순");
		
	}// end main
}//end class
