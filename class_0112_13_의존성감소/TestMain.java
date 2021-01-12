package class_0112_13_의존성감소;

import java.util.Arrays;
import java.util.List;

public class TestMain {
	/*
	 *	DB 연동 아키텍쳐
	 *
	 * 
	 * 	Main <-------> Service <-----> DAO <------> DB(오라클)
	 * 
	 * 	Main 	: 사용자이벤트 발생 + 데이터출력 기능
	 * 	Service	: 중간자 역할 + 트랜잭션 처리
	 * 	DAO		: Database Access Object 패턴이고
	 * 				실제DB, file 접근하는 용도 
	 * 
	 * 	TestMain --> DBService	------> OracleDAO	----> 오라클
	 * 							------> MySQLDAO	----> MySQL	
	 * 
	 * 	==> DB 변경시 DBService 변경 여파가 미친다.
	 * 
	 * 	* 인터페이스 이용한 의존성 감소
	 * 	
	 */
	
	public static void main(String[] args) {
		DBService service = new DBService();
		// Main 입장에서 Oracle 연동하겠다
		
		//service.setDAO(new OracleDAO());
		service.setDAO(new MySQLDAO());
		
		List<String> list = service.connectOracle();
		
		System.out.println(list);
	}
}
