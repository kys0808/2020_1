/**
 * 
 */
package algo;


import java.util.*;


public class Main{
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String,Integer> mp = new HashMap<String,Integer>();
        for(int i=0;i<participant.length;i++) {
        	if(mp.containsKey(participant[i])) {
        		int value = mp.get(participant[i]);
        		mp.put(participant[i],++value);
        	}
        	else {
        		mp.put(participant[i],1);
        	}
        }
        for(int i=0;i<completion.length;i++) {
        	if(mp.containsKey(completion[i])) {
        		int value = mp.get(completion[i]);
        		mp.put(completion[i],--value);
        	}
        }
        for(int i=0;i<participant.length;i++) {
        	if(mp.containsKey(participant[i])) {
        		int value = mp.get(participant[i]);
        		System.out.print(participant[i] + " " + value);
        		System.out.println();
        		if(value >= 1) {
        			answer += participant[i];
        		}
        	}
        }
        return answer;
    }
    public static void main(String[] args){

    }
}