/**
 * 
 */
package algo;

import java.util.*;

class S implements Comparable<S>{	// �帣�� �� ������� ���
	String name;
	int total_play;
	int num;	//���
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

class G implements Comparable<G>{	// �帣�� ������� index
	String name;
	int value;	// ������ �����
	int index;	// ������ index
	G(String name, int value, int index){
		this.name = name;
		this.value = value;
		this.index = index;
	}
	@Override
	public int compareTo(G a) {
		if(this.value < a.value) {	// ���� ����
			return 1;
		}
		else if(this.value == a.value) {	// ������	
			if(this.index > a.index) {		// ���� ����
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
	        HashMap<String, Integer> mp = new HashMap<>();	// �帣�� �� �����
	        HashMap<String, Integer> mp_total = new HashMap<>();	// �帣�� �� ��
	        ArrayList<String> name = new ArrayList<>();
	        
	        for(int i=0;i<genres.length; i++) {
	        	if(mp.containsKey(genres[i])) {	// �̹� ������
	        		mp.put(genres[i],mp.get(genres[i])+plays[i]);
	        		mp_total.put(genres[i],mp_total.get(genres[i])+1);	// �帣�� ���
	        	}
	        	else {
	        		mp.put(genres[i],plays[i]);
	        		mp_total.put(genres[i],1);
	        		name.add(genres[i]);	// �帣�̸� �ߺ����� ������
	        	}
	        }	        
	        ArrayList<S> sorted_g = new ArrayList<>();	// �帣�� �� ����� sort��
	        ArrayList<G> list = new ArrayList<>();	// �� �뷡�� �����
	        
	        for(int i=0;i<genres.length;i++) {
	        	list.add(new G(genres[i],plays[i],i));
	        }
	        Collections.sort(list);
	        for(int i=0;i<name.size();i++) {
	        	// sorted_g (�̸�, �� �����, �� ��)
	        	sorted_g.add(new S(name.get(i), mp.get(name.get(i)), mp_total.get(name.get(i))));
	        }
	        Collections.sort(sorted_g);	// �� ������� ���ĉ�
	        ArrayList<Integer> tmp_answer = new ArrayList<>();
	        
	        for(int i=0;i<sorted_g.size();i++) {
	        	if(sorted_g.get(i).total_play >= 2) {	// �帣�� ��� 2�� �̻��̸� 2�� �̱� ����
	        		int count =0;
	        		for(int j=0;j<list.size();j++) {
	        			if(count == 2) {
	        				break;
	        			}
	        			if(sorted_g.get(i).name.equals(list.get(j).name)) {	//�̸� ������ ������
	        				tmp_answer.add(list.get(j).index);// index �߰�
	        				count++;
	        			}
	        		}
	        	}
	        	else {	// �帣�� ��� 1���� �ϳ��� ����
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