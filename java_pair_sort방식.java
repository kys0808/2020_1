/**
 * 
 */
package algo;


import java.util.*;
import java.io.*;


class Pair implements Comparable<Pair>{
	int x ;
	int y;
	Pair(int x, int y){
		this.x = x;
		this.y = y;
	}
	@Override
	public int compareTo(Pair a) {
		if(this.x >= a.x) {
			if(this.y >= a.y) {
				return 1;
			}
			else {
				return -1;
			}
		}
		else {
			if(this.y <=a.y) {
				return -1;
			}
			else {
				return 1;
			}
		}
	}
}

public class Main{

	public static void main(String[] args) {
		ArrayList<Pair> list = new ArrayList<>();
		list.add(new Pair(1,2));
		list.add(new Pair(2,3));
		list.add(new Pair(3,4));
		list.add(new Pair(1,3));
		Collections.sort(list);
		for(int i=0;i<list.size();i++) {
			System.out.print("(" + list.get(i).x + " "+ list.get(i).y+") ");
		}
	}
}