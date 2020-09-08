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
	        	list.add(new Pair(priorities[i],i));	// �켱������ index�� ����
	        	q.add(priorities[i]);
	        }
	        while(!q.isEmpty()) {
	        	int c_value = q.peek();
	        	boolean find = false;
	        	for(int i=1;i<list.size();i++) {
	        		if(list.get(i).value > c_value) { // �� ū�� ������ �ڷιо����
	        			q.remove();
	        			q.add(c_value);
	        			list.add(new Pair(list.get(0).value, list.get(0).index));
	        			list.remove(0);//pop_front();
	        			find = true;
	        			break;
	        		}
	        	}
	        	if(find == false) {	// �켱���� ��ū�� ������ ����ؾ���
	        		if(list.get(0).index == location) {// ã���� �ϴ°Ÿ�
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