/**
 * 
 */
package algo;


import java.util.*;

public class Main {
	import java.util.*;

	class Solution {
	    public int[] solution(int[] array, int[][] commands) {
	        int [] answer= {};
	        ArrayList<Integer> tmp = new ArrayList<>();
	        ArrayList<Integer> v = new ArrayList<>();
	        for(int i=0;i<commands.length;i++){
	            int a = commands[i][0];
	            int b = commands[i][1];
	            int c = commands[i][2];
	            for(int j = a-1 ; j<b;j++){
	                v.add(array[j]);
	            }
	            Collections.sort(v);    // arraylist �� sort
	            // Arrays.sort(�迭�̸�,start_index, end_index); // array�� sort
	            tmp.add(v.get(c-1));

	            v.clear();
	        }
	        answer = new int[tmp.size()];   // ���� �迭�� ArrayList��ŭ �Ҵ��ϰ� ���
	        for(int i=0;i<tmp.size();i++){
	            answer[i] = tmp.get(i);
	        }
	        return answer;
	    }
	}

}
