package class_0112_14_의존성감소2_인터페이스;

import java.util.Arrays;
import java.util.List;

public class DBService {

	//OracleDAO dao;
	//MySQLDAO dao;
	DBDAO dao;	// 다형성	==> 수정사항을 줄일 수 있다.
	
	
	public void setDAO(DBDAO dao) {
		this.dao = dao;
	}
	
	public List<String> connectOracle(){
//		return dao.connectOracle();
//		return dao.connectMySQL();
		return dao.connect();
	}
	
}
