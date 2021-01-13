package class_0113_16_람다;

import java.util.Arrays;
import java.util.Comparator;

public class lamdaTest5_정렬 {
	public static void main(String[] args) {
		
		// 1. 기존 방식
		String []names = {"kapple","banana","apple"};
		Arrays.sort(names);
		System.out.println("1. 오름차순 정렬:" +Arrays.toString(names));
		
//		// 내림 차순 정렬 ==> java.util.Comparator API 인터페이스 활용, 익명 클래스 활용
//		Comparator<String> comp = new Comparator<String>() {
//			@Override
//			public int compare(String o1, String o2) {
//				return o2.compareTo(o1);
//			}
//		};
		
//		Arrays.sort(names,comp);
//		System.out.println("2. 내림차순 정렬:"+Arrays.toString(names));
		
		Arrays.sort(names,new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				return o2.compareTo(o1);
			}
		});
		System.out.println("2. 내림차순 정렬:"+Arrays.toString(names));

		// 2. 람다 표현식
		Arrays.sort(names, (o1, o2)->o2.compareTo(o1));
		System.out.println("3. 내림차순 정렬:"+Arrays.toString(names));
		
		// 3. 
		Arrays.sort(names, String::compareTo);
		System.out.println("4. 오름차순 정렬:"+Arrays.toString(names));
		
		
		
	}	//end main
}	//end class
