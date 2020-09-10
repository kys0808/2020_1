/**
 * 
 */
package algo;

import java.util.*;



public class Main{

	class N implements Comparable<N>{
		String num;
		N(String num){
			this.num = num;
		}
		@Override
		public int compareTo(N a) {
			return (a.num + this.num).compareTo(this.num+a.num);
		}
	}
	
	class Solution {
	    public String solution(int[] numbers) {
	        String answer = "";
	        ArrayList<N> list = new ArrayList<>();
	        for(int i=0;i<numbers.length;i++) {
	        	String tmp = Integer.toString(numbers[i]);
	        	list.add(new N(tmp));
	        }
	        Collections.sort(list);
	        for(int i=0;i<list.size();i++) {
	        	answer += list.get(i).num;
	        	if(answer.equals("0"))
	        		return answer;
	        }
	        return answer;
	    }
	}
	
	
	
	public static void main(String[] args) {
		Solution s = new Solution();
	}
}