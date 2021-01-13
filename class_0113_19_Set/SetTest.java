package class_0113_19_Set;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;

public class SetTest {
	
	public static void main(String[] args) {
		//	Set 계열 : 순서 없고 중복 불가, HashSet 클래스 사용.
		
		HashSet<String> set = new HashSet<String>();
		
		// 데이터 저장
		set.add("홍길동");
		set.add("이순신");
		set.add("홍길동");
		set.add("유관순");
		
		//	데이터 출력
		System.out.println("1. toString() 이용:"+set);
		
		for(String s : set) {
			System.out.println("2. foreach 이용:"+s);
		}
		
		Iterator<String> iter = set.iterator();
		while(iter.hasNext()) {
			System.out.println("3. Iterator 이용:"+iter.next());
		}
		
		// 추가 메소드
		System.out.println("4. 크기:"+set.size());
		System.out.println("5. 값의 존재 여부:"+set.contains("홍길동"));
		System.out.println("5. 값의 존재 여부:"+set.contains("정조"));
		
		set.remove("유관순");
		System.out.println(set);
		
		Object[] obj = set.toArray();
		System.out.println("7. 배열로 출력:"+Arrays.toString(obj));
		
		set.clear();
		System.out.println(set);
	
	}//end main
}//end class
