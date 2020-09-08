/**
 * 
 */
package algo;

import java.util.*;

class Q implements Comparable<Q>{
	int rq;
	int time;
	Q(int rq, int time){
		this.rq = rq;
		this.time =time;
	}
	@Override
	public int compareTo(Q a) {
		if(this.rq < a.rq) {
			return -1;
		}
		else {
			return 1;
		}
	}
}

class T implements Comparable<T>{
	int rq;
	int time;
	T(int rq, int time){
		this.rq = rq;
		this.time = time;
	}
	@Override
	public int compareTo(T a) {
		if(this.time < a.time) {
			return -1;
		}
		else if(this.time == a.time) {
			if(this.rq < a.rq) {
				return 0;
			}
			else {
				return 1;
			}
		}
		else {
			return 1;
		}
	}
}

public class Main{
	class Solution {
	    public int solution(int[][] jobs) {
	        int answer = 0;
	        PriorityQueue<Q> job = new PriorityQueue<>();	// ��û�ð� ���� ����
	        PriorityQueue<T> wait = new PriorityQueue<>();	// �ҿ�ð� �� ����
	        ArrayList<Q> list1 = new ArrayList<>();
	        ArrayList<T> list2 = new ArrayList<>();
	        
	        for(int i=0;i<jobs.length;i++) {
	        	job.add(new Q(jobs[i][0], jobs[i][1]));	// ��û �ð��� ���ķ� ����

	        }

	        int time =0;
	        
	        while(true) {
	        	if(job.isEmpty() && wait.isEmpty()) {
	        		break;
	        	}
	        	boolean find = false;
	        	while(!job.isEmpty()) {
	        		if(job.peek().rq <= time) {
	        			find = true;
	        			wait.add(new T(job.peek().rq,job.peek().time));
	        			job.remove();
	        		}
	        		else {
	        			break;
	        		}
	        	}
	        	// �ϳ� �۾� ����
	        	if(!wait.isEmpty()) {
	        		time += wait.peek().time;
	        		answer += (time - wait.peek().rq);
	        		wait.remove();
	        	}
	        	else { // ����ð� ���� �۾��Ұ� ������
	        		if(find == false) {
	        			time++;
	        		}
	        	}
	        }
	        answer = answer/(jobs.length);
	        return answer;
	    }
	}
	
	
	public static void main(String[] args) {
		Solution s = new Solution();
	}
}