/**
 * 
 */
package algo;


import java.util.*;


class Pair{
	int x;
	int y;
	Pair(int x,int y){
		this.x = x;
		this.y = y;
	}
}

public class Main {
	static int n,m;
	static int arr[][];
	static int tmp_arr[][];
	static int [] dx = {0,0,1,-1};
	static int [] dy = {1,-1,0,0};
	static int check[][];
	static int answer =0;
	
	
	public static void solve() {
		int count =0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(tmp_arr[i][j] == 0) {
					count++;
				}
			}
		}
		if(answer < count) {
			System.out.println();
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					System.out.print(tmp_arr[i][j] +" ");
				}
				System.out.println();
			}
			answer= count;
		}
	}
	
	public static void bfs() {
		tmp_arr = new int[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				tmp_arr[i][j] = arr[i][j];	// 일단 복사
			}
		}
		Queue<Pair> q = new LinkedList<Pair>();
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(tmp_arr[i][j] == 2) {
					q.add(new Pair(i,j));	//일단 기존의 바이러스 다넣기
				}
			}
		}
		check = new int[n][m];
		
		while(!q.isEmpty()) {
			int current_i =q.peek().x;
			int current_j = q.peek().y;
			q.remove();
			for(int i=0;i<4;i++) {
				int next_i = current_i + dx[i];
				int next_j = current_j + dy[i];
				if(next_i<n && next_j <m && next_i>=0 && next_j >=0) {
					if(check[next_i][next_j] == 0 && tmp_arr[next_i][next_j] == 0) {	
						check[next_i][next_j] =1;
						tmp_arr[next_i][next_j] = 2;
						q.add(new Pair(next_i,next_j));
					}
				}
			}
		}
		solve();
	}
	
	public static void back(int depth) {
		if(depth == 3) {
			bfs();
			return ;
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(arr[i][j]  == 0) {
					arr[i][j] =1;
					back(depth+1);
					arr[i][j] =0;
				}
			}
		}
	}
	
	 public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 n = sc.nextInt();
		 m = sc.nextInt();
		 arr = new int[n][m];
		 
		 for(int i=0;i<n;i++) {	//지도 입력받기
			 for(int j=0;j<m;j++) {
				 arr[i][j] = sc.nextInt();
			 }
		 }
		 
		 back(0);
		 System.out.print(answer);
	 
	 }
	 
}
