import java.util.*;

// 1:20 - 0:49 = 31ºÐ
class Solution {
	HashMap<String,String> mp = new HashMap<>();
	int count =0;
    public ArrayList<String> solution(String[] record) {
        ArrayList<String> answer = new ArrayList<>();
        for(int i=0;i<record.length;i++) {
        	String[] tmp =record[i].split(" ");
        	String first = tmp[0];
        	String uid = tmp[1];
        	if(first.equals("Enter")) {
        		String nick = tmp[2];
        		mp.put(uid, nick);
        		count++;
        	}
        	else if(first.equals("Leave")) {
        		count++;
        	}
        	else if(first.equals("Change")) {
        		String new_nick = tmp[2];
        		if(mp.containsKey(uid)) {
        			mp.remove(uid);
        			mp.put(uid, new_nick);
        		}
        	}
        }
        for(int i=0;i<record.length;i++) {
        	String[] tmp = record[i].split(" ");
        	String first = tmp[0];
        	String uid = tmp[1];
        	if(first.equals("Enter")) {
        		//System.out.println(mp.get(uid)+"´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        		answer.add(mp.get(uid)+"´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        	}
        	else if(first.equals("Leave")) {
        		//System.out.println(mp.get(uid)+"´ÔÀÌ ³ª°¬½À´Ï´Ù.");
        		answer.add(mp.get(uid)+"´ÔÀÌ ³ª°¬½À´Ï´Ù.");
        	}
        }
        
        return answer;
    }
}



public class main {
	
	public static void main(String[] args) {
		Solution s = new Solution();
		s.solution("17");
	}
}

