package class_0112_6_toString_재정의API;

import java.util.Date;
import java.util.List;
import java.util.Arrays;


public class Testmain {

	public static void main(String[] args) {
		// API : 시스템이 제공하는 클래스 ==> 패키지로 제공
		// API문서 : 클래스 정보

		Date d = new Date();
		System.out.println(d);	// d.toString()과 동일
		
		List<String> list = Arrays.asList("aa","bb");
		System.out.println(list);
		
	}

	
	// 결론 : Object의 toString() 메소드는 거의 모든 API가 재정의했다.
	//		==> 따라서 @16진수가 출력되지 않고 실제값이 출력이 된다.
	
	// 우리가 만든 클래스도 toString()메소드를 재정의해서 사용하자
}
