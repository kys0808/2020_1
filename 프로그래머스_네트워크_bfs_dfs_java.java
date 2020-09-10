import java.util.*;

public class main {
	
	
	
	class Solution {
		ArrayList<Integer> graph[];
		int check[];
		
		public void dfs(int parent, int start) {
			if(check[start] != -1 ){
				return;
			}
			else {	//현재 state 방문 안했으면
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
		        		int next = j; // 다음 연결이 있으면
		        		if(start != next) {
		        			graph[start].add(next);
		        		}
	        		}
	        	}
	        } // 그래프별로 연결 노드 번호 넣기 끝
	        for(int i=0;i<n+1;i++) { // 각각 연결상태  정렬
	        	Collections.sort(graph[i]);
	        }
	        
	        check = new int[n+1];
	        for(int i=0;i<n+1;i++) {
	        	check[i] = -1;
	        }// 부모의 방문 번호 저장용

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
