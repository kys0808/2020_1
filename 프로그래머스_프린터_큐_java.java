/**
 * 
 */
package algo;

import java.util.*;


class Pair{
	int value;
	int index;
	Pair(int value, int index){
		this.value = value;
		this.index = index;
	}
}
public class Main{
	class Solution {
	    public int solution(int[] priorities, int location) {
	        int answer = 0;
	        ArrayList<Pair> list = new ArrayList<>();
	        Queue<Integer> q = new LinkedList<>();
	        for(int i=0;i<priorities.length;i++) {
	        	list.add(new Pair(priorities[i],i));	// 우선순위와 index를 저장
	        	q.add(priorities[i]);
	        }
	        while(!q.isEmpty()) {
	        	int c_value = q.peek();
	        	boolean find = false;
	        	for(int i=1;i<list.size();i++) {
	        		if(list.get(i).value > c_value) { // 더 큰거 있으면 뒤로밀어야지
	        			q.remove();
	        			q.add(c_value);
	        			list.add(new Pair(list.get(0).value, list.get(0).index));
	        			list.remove(0);//pop_front();
	        			find = true;
	        			break;
	        		}
	        	}
	        	if(find == false) {	// 우선순위 더큰게 없으면 출력해야지
	        		if(list.get(0).index == location) {// 찾고자 하는거면
	        			break;
	        		}
	        		else {
	        			answer++;
	        			q.remove();
	        			list.remove(0);
	        		}
	        	}
	        }
	        return answer+1;
	    }
	}
	public static void main(String[] args) {
		Solutions s = new Solutions();
	}
}