import java.util.*;

public class main {
	
	
	
	class Solution {
		ArrayList<Integer> graph[];
		int check[];
		
		public void dfs(int parent, int start) {
			if(check[start] != -1 ){
				return;
			}
			else {	//���� state �湮 ��������
				check[start] = parent;
				for(int i=0;i<graph[start].size();i++) {
					int next = graph[start].get(i);
					dfs(parent,next);
				}		
			}
		}
		
	    public int solution(int n, int[][] computers) {
	        int answer = 0;
	        graph = new ArrayList[n+1];
	        for(int i=0;i<n+1;i++) {
	        	graph[i] = new ArrayList<>();
	        }
	        for(int i=0; i<computers.length;i++) {
	        	int start = i;
	        	for(int j=0;j<computers[i].length; j++) {
	        		if(computers[i][j] == 1) {
		        		int next = j; // ���� ������ ������
		        		if(start != next) {
		        			graph[start].add(next);
		        		}
	        		}
	        	}
	        } // �׷������� ���� ��� ��ȣ �ֱ� ��
	        for(int i=0;i<n+1;i++) { // ���� �������  ����
	        	Collections.sort(graph[i]);
	        }
	        
	        check = new int[n+1];
	        for(int i=0;i<n+1;i++) {
	        	check[i] = -1;
	        }// �θ��� �湮 ��ȣ �����

	        for(int i=0;i<n;i++) {
	        	dfs(i,i);
	        }
	        HashSet<Integer> s = new HashSet<>();
	        for(int i=0;i<n;i++) {
	        	s.add(check[i]);
	        }
	        answer =s.size();
	        return answer;
	    }
	}

	public static void main(String[] args) {
		System.out.print("hello");
	}
}
