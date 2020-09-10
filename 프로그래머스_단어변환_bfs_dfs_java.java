import java.util.*;

public class main {
	
	
	class Solution {
		int check[];	// 방문 체크용
		int answer =9999;
		int check_count(String status, String word) {	// 다른 갯수차이 찾기
			int count =0;
			for(int i=0;i<status.length();i++) {
				if(status.charAt(i) != word.charAt(i)) {
					count++;
				}
			}
			//System.out.println(status +" "+ word+" "+count);
			return count;
		}
		
		void back(String begin, String target, String status, int depth,String[] words) {
			if(status.equals(target) == true) {
				System.out.println(depth);
				if(answer > depth) {
					answer = depth;
				}
				return;
			}
			
			for(int i=0;i<words.length;i++) {
				if(check[i] == 0) {
					int count = check_count(status,words[i]);	//서로 다른 count 세봐야지
					if(count == 1) {
						check[i] = 1;	//방문 안한 word고 count == 1이라면 진행
						String before = status;
						status = words[i];
						back(begin, target,status,depth+1,words);
						status = before;
						check[i] = 0;
					}
				}
			}
		}
		
	    public int solution(String begin, String target, String[] words) {
	    	check = new int[words.length];
	    	for(int i=0;i<check.length;i++) {
	    		check[i] = 0;
	    	}
	    	boolean going = false;
	    	for(int i=0;i<words.length;i++) {
	    		if(words[i].equals(target) == true) {
	    			going= true;
	    			break;
	    		}
	    	}
	    	if(going == true)
	    		back(begin,target,begin,0,words);
	    	else 
	    		answer =0;
	        return answer;
	    }
	}

	public static void main(String[] args) {
		System.out.print("hello");
	}
}
