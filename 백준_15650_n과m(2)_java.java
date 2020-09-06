/**
 * 
 */
package algo;


import java.util.*;


public class Main{
	static int n,m;
	static ArrayList<Integer> list;
	static int check[];
	static void back(int depth,int index) {
		if(depth == m) {
			for(int i=0;i<list.size();i++) {
				System.out.print(list.get(i)+" ");
			}
			System.out.println();
			return ;
		}
		for(int i=index;i<=n;i++) {
			if(check[i] == 0) {
				check[i] = 1;
				list.add(i);
				back(depth+1,i);
				list.remove(list.size()-1);
				check[i] =0;
			}
		}
		
	}
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		m = sc.nextInt();
		list = new ArrayList<Integer>();
		check = new int[n+1];
		back(0,1);

	}
}
