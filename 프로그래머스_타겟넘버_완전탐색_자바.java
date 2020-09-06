/**
 * 
 */
package algo;


import java.util.*;

public class Main {
	    public static int oper_size;
	    public static int answer =0;
	    
	    public void dfs(int[] numbers,int depth,int sum, int target){
	        if(depth == numbers.length){
	            if(sum == target)
	                answer++;                        
	            return;
	        }
	        dfs(numbers,depth+1, sum + numbers[depth],target);
	        dfs(numbers,depth+1, sum - numbers[depth],target);
	    }
	    public int solution(int[] numbers, int target) {
	        oper_size = numbers.length - target -1;
	        dfs(numbers,0,0,target);
	        return answer;
	    }
	 public static void main(String[] args) {

	 }
}
