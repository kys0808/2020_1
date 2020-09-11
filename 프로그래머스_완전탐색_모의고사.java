import java.util.*;

public class main {
	
	class Pair implements Comparable<Pair>{
		int count;
		int num;
		Pair(int count, int num){
			this.count = count;
			this.num= num;
		}
		@Override
		public int compareTo(Pair a) {
			if(this.num < a.num) {
				return -1;
			}
			else {
				return 1;
			}
		}
	}
	
	class Solution {
		
	    public int[] solution(int[] answers) {
	        int[] answer = {};
	        ArrayList<Integer> list1 = new ArrayList<>();
	        ArrayList<Integer> list2 = new ArrayList<>();
	        ArrayList<Integer> list3 = new ArrayList<>();
	        int check1[] = {1,2,3,4,5};
	        int check2[] = {2,1,2,3,2,4,2,5};
	        int check3[] = {3,3,1,1,2,2,4,4,5,5};
	        for(int i=0;i<answers.length;i++) {
	        	list1.add(check1[i%5]);
	        	list2.add(check2[i%8]);
	        	list3.add(check3[i%10]);
	        }
	        int count[] = new int[3];
	        for(int i=0;i<answers.length;i++) {
	        	if(list1.get(i) == answers[i]) {
	        		count[0]++;
	        	}
	        	if(list2.get(i) == answers[i]) {
	        		count[1]++;
	        	}
	        	if(list3.get(i) == answers[i]) {
	        		count[2]++;
	        	}
	        }
	        
	        ArrayList<Pair> tmp = new ArrayList<>();
	        int max_count =0;
	        for(int i=0;i<3;i++) {
	        	if(max_count<count[i]) {
	        		max_count = count[i];
	        	}
	        	tmp.add(new Pair(count[i],i+1));
	        }
	        Collections.sort(tmp);
	        ArrayList<Integer> tmp_answer = new ArrayList<>();
	        //System.out.println(max_count);
	        for(int i=0;i<tmp.size();i++) {
	        	//System.out.println(tmp.get(i).count +" "+tmp.get(i).num);
	        	if(tmp.get(i).count == max_count) {
	        		tmp_answer.add(tmp.get(i).num);
	        	}
	        }
	        answer = new int[tmp_answer.size()];
	        for(int i=0;i<tmp_answer.size();i++) {
	        	answer[i] = tmp_answer.get(i);
	        }
	        return answer;
	    }
	}
	public static void main(String[] args) {
		System.out.print("hello");
	}
}
