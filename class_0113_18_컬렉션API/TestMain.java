package class_0113_18_컬렉션API;

public class TestMain {

	public static void main(String[] args) {
		/*
		 * 		자바의 데이터 저장 방법 3가지
		 * 
		 * 		1. 변수
		 * 			- 하나의 데이터 저장
		 * 			- 기본형 변수와 참조형 변수
		 * 
		 * 		2. 배열
		 * 			- 여러 데이터 저장용
		 * 			- 참조형 변수
		 * 			- 특징: 	동일한 데이터만 저장 가능
		 * 					크기 변경 불가 ( 데이터 관리 어렵다. )
		 * 					접근시 인덱스(첨자) 사용
		 * 					배열과 관련된 메소드가 없다. (Arrays 유틸리티 제외)
		 * 					배열크기 : 배열명.length	(상수)
		 * 
		 * 		3. Collection API
		 * 			- 여러 데이터 저장용
		 * 			- 참조형 변수
		 * 			- 특징: 	모든 데이터 저장 가능
		 * 					크기 변경 가능 ( 추가, 삽입, 수정, 삭제 )
		 * 					접근시 메소드를 사용
		 * 					다양한 메소드를 제공
		 * 					컬렉션크기 : 변수명.size()
		 * 					문자열의 길이 : 	String n = "hello";
		 * 									n.length();
		 * 				
		 * 			*컬렉션 API 계층 구조
		 * 
		 * 				java.util 패키지
		 * 
		 *	 				Collection (인터페이스)								Map(인터페이스)
		 *						|													|
		 *		Set(인터페이스)		List(인터페이스)										|
		 *			|					|
		 *			|					|
		 *		HashSet(클래스*)		ArrayList(클래스)								HashMap(클래스), Properties(클래스)
		 * 		TreeSet(클래스)		Vector(클래스)
		 * 
		 * 		Set 계열 	: 저장되는 데이터의 순서가 없고 중복저장 불가 (동일한 값은 한번만 저장, 중복제거 기능 포함)
		 * 		List 계열	: 저장되는 데이터의 순서가 있고 중복저장 가능
		 * 		==> Set과 List는 데이터만 저장된다.
		 * 
		 * 		Map 계열
		 *		==> 데이터와 데이터에 해당되는 이름(key) 쌍으로 저장된다. (key/value 쌍)
		 *		==> key 이용해서 value를 얻는다. (검색속도가 빠르다)
		 * 
		 */

	}

}
