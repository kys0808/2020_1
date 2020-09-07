/**
 * 
 */
package algo;

import java.util.*;

class Pair{
	String key;
	int value;
	Pair(String key, int value){
		this.key = key;
		this.value = value;
	}
}
public class Main{
	class Solution {
		public static int[] solution(String[] genres, int[] plays) {
            int [] answer= {};
			HashMap<String, Integer> mp = new HashMap<>();
			ArrayList<Pair> list = new ArrayList<>();
			
			for(int i=0;i<genres.length;i++) {
				if(!mp.containsKey(genres[i])) {
					list.add(new Pair(genres[i],0));
					mp.put(genres[i], plays[i]);
				}
				else {
					mp.put(genres[i],mp.get(genres[i])+plays[i]);
				}
			}
			for(int i=0;i<mp.size();i++) {
				list.get(i).value = mp.get(list.get(i));
			}
			for(int i=0;i<list.size();i++) {
				System.out.print(list.get(i).key + " " +list.get(i).value);
			}
			return answer;
		}
    }
	public static void main(String[] args) {
		String[] genres = {"classic","pop","classic","classic","pop"};
		int[] plays = {500,600,150,800,2500};
		Solution.solution(genres,plays);
	}
}