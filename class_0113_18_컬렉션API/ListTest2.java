package class_0113_18_컬렉션API;

import java.util.ArrayList;

public class ListTest2 {

	public static void main(String[] args) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(1);
		list.add(2);
		list.add(3);
		
		System.out.println(list);
		list.remove(1);	// 1은 값이 아닌 index로 적용된다.
		System.out.println(list);
		
	}// end main

}
