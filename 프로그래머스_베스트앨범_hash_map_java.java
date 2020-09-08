/**
 * 
 */
package algo;

import java.util.*;

class S implements Comparable<S>{	// 장르별 총 재생수와 곡수
	String name;
	int total_play;
	int num;	//곡수
	S(String name, int total_play, int num){
		this.name = name;
		this.total_play = total_play;
		this.num = num;
	}
	@Override
	public int compareTo(S a) {
		if(this.total_play < a.total_play) {
			return 1;
		}
		else {
			return -1;
		}
	}
}

class G implements Comparable<G>{	// 장르별 재생수와 index
	String name;
	int value;	// 각자의 재생수
	int index;	// 각자의 index
	G(String name, int value, int index){
		this.name = name;
		this.value = value;
		this.index = index;
	}
	@Override
	public int compareTo(G a) {
		if(this.value < a.value) {	// 내림 차순
			return 1;
		}
		else if(this.value == a.value) {	// 같으면	
			if(this.index > a.index) {		// 오름 차순
				return 0;
			}
			else {
				return -1;
			}
		}
		else {
			return -1;
		}
	}
}

public class Main{
	class Solution {
	    public int[] solution(String[] genres, int[] plays) {
	        int[] answer = {};
	        HashMap<String, Integer> mp = new HashMap<>();	// 장르별 총 재생수
	        HashMap<String, Integer> mp_total = new HashMap<>();	// 장르별 곡 수
	        ArrayList<String> name = new ArrayList<>();
	        
	        for(int i=0;i<genres.length; i++) {
	        	if(mp.containsKey(genres[i])) {	// 이미 있으면
	        		mp.put(genres[i],mp.get(genres[i])+plays[i]);
	        		mp_total.put(genres[i],mp_total.get(genres[i])+1);	// 장르별 곡수
	        	}
	        	else {
	        		mp.put(genres[i],plays[i]);
	        		mp_total.put(genres[i],1);
	        		name.add(genres[i]);	// 장르이름 중복없이 모으기
	        	}
	        }	        
	        ArrayList<S> sorted_g = new ArrayList<>();	// 장르별 총 재생수 sort용
	        ArrayList<G> list = new ArrayList<>();	// 각 노래들 재생수
	        
	        for(int i=0;i<genres.length;i++) {
	        	list.add(new G(genres[i],plays[i],i));
	        }
	        Collections.sort(list);
	        for(int i=0;i<name.size();i++) {
	        	// sorted_g (이름, 총 재생수, 곡 수)
	        	sorted_g.add(new S(name.get(i), mp.get(name.get(i)), mp_total.get(name.get(i))));
	        }
	        Collections.sort(sorted_g);	// 총 재생수로 정렬됌
	        ArrayList<Integer> tmp_answer = new ArrayList<>();
	        
	        for(int i=0;i<sorted_g.size();i++) {
	        	if(sorted_g.get(i).total_play >= 2) {	// 장르별 곡수 2개 이상이면 2개 뽑기 진행
	        		int count =0;
	        		for(int j=0;j<list.size();j++) {
	        			if(count == 2) {
	        				break;
	        			}
	        			if(sorted_g.get(i).name.equals(list.get(j).name)) {	//이름 같은거 있으면
	        				tmp_answer.add(list.get(j).index);// index 추가
	        				count++;
	        			}
	        		}
	        	}
	        	else {	// 장르별 곡수 1개면 하나만 선택
	        		for(int j=0;j<list.size();j++) {
	        			if(sorted_g.get(i).name.equals(list.get(j).name)) {
	        				tmp_answer.add(list.get(j).index);
	        				break;
	        			}
	        		}
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
		Solutions s = new Solutions();
	}
}