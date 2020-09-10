import java.util.*;

public class main {
	
	class N implements Comparable <N>{
		int num;
		N (int num){
			this.num = num;
		}
		@Override
		public int compareTo(N a) {
			if(this.num < a.num) {
				return 1;
			}
			else {
				return -1;
			}
		}
	}
	class Solution {
	    public int solution(int[] citations) {
	        int answer = 0;
	        ArrayList<N> list = new ArrayList<>();
	        for(int i=0;i<citations.length; i++) {
	        	list.add(new N (citations[i]));
	        }
	        Collections.sort(list);
	        int index =0;
	        while(index < list.size()) {
	        	if(list.get(index).num <= index) {
	        		break;
	        	}
	        	index++;
	        }
	        return index;

	    }
	}

	public static void main(String[] args) {
		System.out.print("hello");
	}
}
