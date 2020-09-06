/**
 * 
 */
package algo;


import java.util.*;

public class Main {
    public static int[] solution(int[] prices) {
		int []answer = new int[prices.length];
		
		for(int i=0;i<prices.length;i++) {
			int time =0;
			for(int j=i+1;j<prices.length;j++) {
                if(i+1 <prices.length){
                    if(prices[i] <= prices[j]){
                        time++;
                    }
                    else{
                        time++;
                        break;
                    }
                }
            }
            answer[i] = time;
		}
		for(int i=0;i<answer.length;i++) {
			System.out.print(answer[i] + " ");
		}
		System.out.println("");
		return answer;
    }
	 public static void main(String[] args) {
		 int[] prices = {1,2,3,2,3};
		 solution(prices);
	 }
}
