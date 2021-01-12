package class_0112_13_의존성감소;

import java.util.Arrays;
import java.util.List;

public class DBService {

	//OracleDAO dao;
	MySQLDAO dao;
	
	public void setDAO(OracleDAO dao) {
		this.dao = dao;
	}
	
	public List<String> connectOracle(){
//		return dao.connectOracle();
		return dao.connectMySQL();
	}
	
}
