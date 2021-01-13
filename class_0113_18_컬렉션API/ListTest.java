package class_0113_18_컬렉션API;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class ListTest {

	public static void main(String[] args) {
		// List 계열	: 순서가 있고 중복 가능, ArrayList 클래스 사용
		
		// 1. 생성
		ArrayList<String> list = new ArrayList<String>();
		
		// 2. 데이터 저장(추가)
		list.add("김영수");
		list.add("이순신");
		list.add("유관순");
		list.add("김영수");
		list.add("정조");
		
		// 3. 데이터 삽입
		list.add(0,"강감찬");
		
		// 4. 데이터 수정
		list.set(0, "김송옥");
		
		//5. 데이터 삭제
		list.remove(0);			// 0번째 위치 삭제
		list.remove("유관순");	//값으로 삭제
		
		// 데이터 출력
		System.out.println("1. 데이터 출력방법: toString():"+list);	// list.toString()동일
		
		for(String string : list) {
			System.out.println("2.foreach문 사용:"+string);
		}
		
		System.out.println("3. 개별적인 위치값 출력:" +list.get(0));
		System.out.println("3. 개별적인 위치값 출력:" +list.get(3));
		
		for (int i = 0; i < list.size(); i++) {
			System.out.println("4. 일반for문: "+list.get(i));
		}
		
		//java.util.Iterator API 활용	==> 컬렉션에 저장된 데이터를 순회하면서 값을 얻어올 때 사용
		Iterator<String> iter = list.iterator();
		while(iter.hasNext()) {// .hasNext()는 boolean값, 있으면 true, 없으면 false;
			System.out.println("5. Iterator: "+iter.next());
		}
		
		// 추가 메소드
		System.out.println("6. 리스트 길이:"+list.size());
		System.out.println("7. 값의 존재 여부:"+list.contains("정조"));
		System.out.println("7. 값의 존재 여부:"+list.contains("영조"));
		
		Object [] obj = list.toArray();
		System.out.println("8. 배열로 변경: "+Arrays.toString(obj));
		System.out.println("9. 특정값의 위치: "+ list.indexOf("정조"));
		
//		list.clear();
//		System.out.println("9. 전체 삭제 "+list);
		
		// 부분 리스트
		System.out.println("원본 :"+ list);
		List<String> sublist = list.subList(0, 3);
		
		
	}// end main
}//end class
