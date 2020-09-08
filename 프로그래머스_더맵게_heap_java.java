/**
 * 
 */
package algo;

import java.util.*;

public class Main{
	class Solution {
	    public int solution(int[] scoville, int K) {
	        int answer = 0;
	        PriorityQueue<Integer> pq = new PriorityQueue<>();
	        
	        ArrayList<Integer> list = new ArrayList<>();
	        for(int i=0;i<scoville.length; i++) {
	        	pq.add(scoville[i]);
	        }

	        while(true) {
	        	if(pq.size()>=2) {
	        		int a = pq.peek();
	        		pq.remove();
	        		int b = pq.peek();
	        		pq.remove();
	        		pq.add(a+b*2);
	        		answer += 1;
	        	}
	        	else {
	        		if(pq.peek() <K)
	        			return -1;
	        	}
	        	if(pq.peek() >= K) {
	        		break;
	        	}
	        }
	        return answer;
	    }
	}
	
	
	public static void main(String[] args) {
		Solution s = new Solution();
	}
}