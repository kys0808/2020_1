/**
 * 
 */
package algo;

import java.util.*;

class Pair{
	int weight;
	int time;
	Pair(int weight, int time){
		this.weight = weight;
		this.time = time;
	}
}

public class Main{
	class Solution {
	    public int solution(int bridge_length, int weight, int[] truck_weights) {
	        int answer = 0;
	        int time =1;
	        int current_weight =0;
	        Queue<Integer> q1 = new LinkedList<>();
	        for(int i=0;i<truck_weights.length;i++) {
	        	q1.add(truck_weights[i]);
	        }
	        
	        Queue<Pair> q = new LinkedList<Pair>();

	        while(true) {
	        	if(!q.isEmpty()) {
	        		if((time - q.peek().time) == bridge_length) {
	        			current_weight -= q.peek().weight;
	        			q.remove();
	        		}
	        	}
	        	if(!q1.isEmpty()) {
	        		if(current_weight + q1.peek() <= weight) {
	        			current_weight += q1.peek();
	        			q.add(new Pair(q1.peek(),time));
	        			q1.remove();
	        		}
	        	}
	        	if(q1.isEmpty() && q.isEmpty())
	        		break;
	        	time++;
	        }
	        answer =time;
	        return answer;
	    }
	}
	public static void main(String[] args) {
		Solutions s = new Solutions();
	}
}