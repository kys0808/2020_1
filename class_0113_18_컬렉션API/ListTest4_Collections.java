package class_0113_18_컬렉션API;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Person{
	String name;
	int age;
	
	public Person() {
		// TODO Auto-generated constructor stub
	}
	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	
	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + "]";
	}
}//end class


// 이름있는 클래스
class MyComparator implements Comparator<Person>{
	@Override
	public int compare(Person o1, Person o2) {
//		return o1.age-o2.age;	//오름 차순
//		return o2.age-o1.age;	//내림 차순
//		return Integer.compare(o1.age,o2.age);	//오름차순
		return Integer.compare(o2.age,o1.age);	//내림차순
	}
}


public class ListTest4_Collections {

	public static void main(String[] args) {
		List<Person> list = Arrays.asList(new Person("홍길동",34),
				new Person("홍길동1",14),
				new Person("홍길동2",54),
				new Person("홍길동3",24),
				new Person("홍길동4",74)
				);
		
		//1. 정렬
		Collections.sort(list,new MyComparator());
		
		//2. 최대/최소
		Person max = Collections.max(list,new MyComparator());
		Person min = Collections.min(list,new MyComparator());
		
		System.out.println("2. age 최대값: "+max);
		System.out.println("3. age 최솟값: "+min);
		
	}// end main
}//end class
