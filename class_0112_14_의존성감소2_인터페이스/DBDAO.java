package class_0112_14_의존성감소2_인터페이스;

import java.util.List;

public interface DBDAO {

	// DB 연동시 필요한 메소드를 추상 메소드
	
	public abstract List<String> connect();

}
