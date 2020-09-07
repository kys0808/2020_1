/**
 * 
 */
package algo;

import java.util.*;

public class Main{
	class Solution {
	    public boolean solution(String[] phone_book) {
	        boolean answer = true;
	        ArrayList<String> sortedList = new ArrayList<>();
	        for(int i=0;i<phone_book.length;i++) {
	        	sortedList.add(phone_book[i]);
	        }
	        Collections.sort(sortedList);
	        for(int i=0;i<sortedList.size()-1;i++){
	        	String a = sortedList.get(i);
	        	String b = sortedList.get(i+1);
	        	int len_a =a.length();
	        	int len_b =b.length();
	        	if(len_a < len_b) {
	        		String tmp = b.substring(0,len_a);
	        		if(a.equals(tmp)) {
	        			answer = false;
	        			break;
	        		}
	        	}
	        	else {
	        		String tmp = a.substring(0,len_b);
	        		if( b.equals(tmp)) {
	        			answer = false;
	        			break;
	        		}
	        	}
	        }
	        return answer;
	    }
	}
	public static void main(String[] args) {
		
	}
}

ArrayList<String> sortedList = new ArrayList<>();

