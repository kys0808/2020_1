package class_0113_20_Map;

import java.util.HashMap;
import java.util.Properties;
import java.util.Set;


public class MapTest {

	public static void main(String[] args) {
		// Map 계열 : key/value 쌍으로 저장. key이용해서 value 얻는다. 순서가 없다. HashMap, Properties 사용
		
		//	1. HashMap		==> key/value가 임의의 데이터인 경우에 사용
		HashMap<String, String> map = new HashMap<String, String>();	// 다형성 적용
		map.put("p1", "홍길동1");
		map.put("p2", "홍길동2");
		map.put("p3", "홍길동3");
		map.put("p4", "홍길동4");
		
		// 데이터 출력
		System.out.println("1. toString() 이용:"+map);
		System.out.println("2. key 이용:"+map.get("p1"));
		System.out.println("2. key 이용:"+map.get("p3"));
		// 존재하지 않는 key값을 주면 null이 나온다.
		System.out.println("2. key 이용:"+map.get("p5"));
		
		//key만 반환
		Set<String> keys = map.keySet();
		System.out.println("3. key만 출력:" +keys);
		
		// 값 수정
		map.replace("p1", "이순신");
		System.out.println("4. key이용한 값변경:"+map);
		// 값 삭제
		map.remove("p2");
		System.out.println("5. key이용한 값 삭제:"+map);
		
		System.out.println("6. map 크기:"+map.size());
		
		// 전체 삭제
		map.clear();
		System.out.println("7. 전체 삭제:"+map);
		
		//	2. Properties	==> key, value가 모두 String인 경우에 최적화 되어있다.
		Properties props = new Properties();
		
		props.setProperty("p1","홍길동1");
		props.setProperty("p2","홍길동2");
		props.setProperty("p3","홍길동3");
		props.setProperty("p4","홍길동4");
		
		System.out.println("8. Properties 출력:"+props.getProperty("p1"));
		
		// 운영체제의 시스템 환경 변수 ==> key/value 쌍으로 되어 있고 문자열로 설정되어 있다.
		Properties systemProperties = System.getProperties();
		Set<String> keys2 = systemProperties.stringPropertyNames();
		for(String key : keys2) {
			System.out.println(key +" = "+systemProperties.getProperty(key));
		}
		
		
	}//end main
}//end class
