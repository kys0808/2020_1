package class_0113_16_람다;

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
	
	
}// end Person

public class lamdaTest6_정렬2_Person {
	public static void main(String[] args) {
		
		// 1. 기존 방식
		// List로 관리
		List<Person> list = Arrays.asList(new Person("홍길동",15),
							new Person("홍길동1",10),
							new Person("홍길동2",50),
							new Person("홍길동3",21)
				);
		// 배열인 경우 	--> Arrays.sort();
		// 리스트인 경우 	--> Colletions.sort();
		Collections.sort(list, new Comparator<Person>() {
			@Override
			public int compare(Person o1, Person o2) {
				return o1.age-o2.age;	// 오름차순
			//	return o2.age-o1.age;	// 내림차순
			}
		});
		System.out.println("1. 리스트정렬 :"+list);
		
		// 2. 람다표현식
		Collections.sort(list, (Person o1, Person o2)->o1.age-o2.age);
		System.out.println("2. 람다 표현식 오름차순 리스트정렬 :"+list);
		
		
	}	//end main
}	//end class
