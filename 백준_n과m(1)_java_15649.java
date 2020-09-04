/**
 * 
 */
package algo;

import java.util.*;

public class Main {
	static int list[];
	static int check[];
	static int n,m;
	
	public static void back(int cnt) {
		if(cnt == m) {
			for(int i=0;i<m;i++) {
				System.out.print(list[i]+" ");
			}
			System.out.println("");
			return ;
		}
		
		for(int i=1;i<=n;i++) {
			if(check[i] == 0) {
				check[i] = 1;
				list[cnt] = i;
				back(cnt+1);
				check[i] = 0;
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		check = new int[10];
		list = new int[10];

		back(0);
	}
}
