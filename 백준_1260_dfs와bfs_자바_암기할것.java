/**
 * 
 */
package algo;


import java.util.*;

public class Main {
	static public int n,m,v;
	static ArrayList<Integer>[] list;
	static int check[];
	
	public static void dfs(int index) {
		if(check[index] == 1) {
			
			return;
		}
		check[index] = 1;
		System.out.print(index+" ");
		for(int i=0;i<list[index].size();i++) {
			int next = list[index].get(i);
			if(check[next] == 0) {
				dfs(next);
			}
		}
	}
	
	public static void bfs(int start_index) {
		Queue<Integer> q = new LinkedList<>();
		q.add(start_index);
		check[start_index] =1;
		while(!q.isEmpty()) {
			int current = q.poll();	// front 반환하고 pop();
			System.out.print(current+" ");
			for(int i=0;i<list[current].size();i++) {
				int next = list[current].get(i);
				if(check[next] == 0) {
					check[next] = 1;
					q.add(next);
				}
			}
		}
	}
	
	 public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 n = sc.nextInt();
		 m = sc.nextInt();
		 v = sc.nextInt();	// start point
		 check = new int[n+1];
		 list = new ArrayList[n+1];
		 for(int i=1;i<n+1;i++) {
			 list[i] = new ArrayList<Integer>();
		 }
		 for(int i=0;i<m;i++) {
			 int a = sc.nextInt();
			 int b = sc.nextInt();
			 list[a].add(b);
			 list[b].add(a);
		 }
		 for(int i=1;i<=n;i++) {
			 list[i].sort(Comparator.naturalOrder());
		 }
		 check = new int[n+1];
		 dfs(v);
		 System.out.println();
		 check = new int[n+1];	// 초기화 다시
		 bfs(v);
		 System.out.println();
	 }
}
