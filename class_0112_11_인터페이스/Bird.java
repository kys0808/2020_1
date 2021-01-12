package class_0112_11_인터페이스;

/*
 * 		날아다니는 기능 메소드 fly() 어디에 추가?
 * 
 * 		1. Pet 클래스 추가
 * 			==> fly 기능이 없는 Cat, Dog이 문제가 된다.
 * 
 * 		2. Bird 클래스 추가
 * 			==> 날아다니는 애가 Bird뿐만 아니라 Bird2클래스가 있다면, 일일이 추가해야하는 문제
 * 
 * 		3. 인터페이스를 이용
 * 			==> 1번, 2번 문제 해결 가능하다.
 */


public class Bird extends Pet implements Flyer{	// implements는 인터페이스를 받을 때
	
	double weight;
	
	public Bird() {
		// TODO Auto-generated constructor stub
	}

	public Bird(String name, int age) {
		super(name, age);
		// TODO Auto-generated constructor stub
	}

	public Bird(String name, int age, double weight) {
		super(name, age);
		this.weight = weight;
	}

	public double getWeight() {
		return weight;
	}

	public void setWeight(double weight) {
		this.weight = weight;
	}

	@Override
	public void eat() {
		System.out.println("Bird.eat");
	}

	@Override
	public void sleep() {
		System.out.println("Bird.sleep");
	}

	@Override
	public String toString() {
		return "Bird [weight=" + weight + ", name=" + name + ", age=" + age + "]";
	}

	@Override
	public void fly() {
		// TODO Auto-generated method stub
		System.out.println("Bird.fly");
	}

}
