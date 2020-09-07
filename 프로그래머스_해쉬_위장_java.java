/**
 * 
 */
package algo;

import java.util.*;

public class Main{
	class Solution {
	    public int solution(String[][] clothes) {
	        int answer = 1;
	        HashMap<String,Integer> mp = new HashMap<>();
	        ArrayList<String> list = new ArrayList<>();
	        
	        for(int i=0;i<clothes.length;i++) {
	        	if(mp.containsKey(clothes[i][1])) {
	        		int value = mp.get(clothes[i][1]);
	        		mp.put(clothes[i][1],++value);
	        	}
	        	else {
	        		list.add(clothes[i][1]);
	        		mp.put(clothes[i][1], 1);
	        	}
	        }
	        for(int i=0;i<list.size();i++) {
	        	int value = mp.get(list.get(i));
	        	answer*= (value+1);
	        }
	        answer -=1;
	        return answer;
	    }
	}
	public static void main(String[] args) {
		
	}
}

ArrayList<String> sortedList = new ArrayList<>();

