#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int t;
int st[2][100001];
int dp[2][100001];
int answer = 0;
int n;

int main(){
	cin >> t;
	while (t--){
		cin >> n;
		memset(dp, 0, sizeof(dp));
		memset(st, 0, sizeof(st));
		answer = 0;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < n; j++){
				cin >> st[i][j];
			}
		}
		dp[0][0] = st[0][0];
		dp[1][0] = st[1][0];
		dp[0][1] = st[0][1] + dp[1][0];
		dp[1][1] = st[1][1] + dp[0][0];
		for (int i = 2; i <= n; i++){
			dp[0][i] = st[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = st[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}
		answer = max(dp[0][n-1], dp[1][n-1]);
		cout << answer << endl;
	}
}