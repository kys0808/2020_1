package class_0113_16_람다;



@FunctionalInterface	// 인터페이스가 반드시 단 하나의 추상메소드만 가지도록 강제하는 어노테이션이다.
public interface Flyer {
	//	가. 파라미터변수 없고 리턴값 없는 경우
	public abstract void fly();
}
