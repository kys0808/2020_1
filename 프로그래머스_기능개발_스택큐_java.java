/**
 * 
 */
package algo;

import java.util.*;

public class Main{
	class Solution {
	    public int[] solution(int[] progresses, int[] speeds) {
	    	int[] answer = {};
	    	ArrayList<Integer> list = new ArrayList<>();
	    	for(int i=0;i<progresses.length;i++) {
	    		if((100-progresses[i]) % speeds[i] != 0) {
	    			list.add((100-progresses[i])/speeds[i]+1);
	    		}
	    		else{
	    			list.add((100-progresses[i])/speeds[i]);
	    		}
	    	}
	    	ArrayList <Integer> tmp_list = new ArrayList<>();
	    	for(int i=0;i<list.size();i++) {
	    		tmp_list.add(list.get(i));
	    	}
	    	int []check = new int[tmp_list.size()];
	    	ArrayList <Integer> tmp_answer = new ArrayList<>();
	    	Collections.sort(tmp_list);

	    	for(int i=0;i<tmp_list.size();i++) {
	    		int time = tmp_list.get(i);
	    		int count =0;
	    		for(int j=0;j<list.size();j++) {
	    			if(time >= list.get(j)) {
	    				if(check[j] == 0) {
	    					check[j]= 1;
	    					count++;
	    				}
	    			}
	    			else {
	    				if(check[j] == 1) {
	    					continue;
	    				}
	    				else {
	    					break;
	    				}
	    			}
	    		}
	    		if(count != 0)
	    			tmp_answer.add(count);
	    	}
	    	answer = new int[tmp_answer.size()];
	    	for(int i=0;i<tmp_answer.size();i++) {
	    		answer[i] = tmp_answer.get(i);
	    	}
	    	
	    	return answer;
	    }
	}
}