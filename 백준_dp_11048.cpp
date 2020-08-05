#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int status[1001][1001];
int dp[1001][1001];
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> status[i][j];
		}
	}
	dp[1][1] = status[1][1];
	dp[1][2] = dp[1][1] + status[1][2];
	dp[2][1] = dp[1][1] + status[2][1];

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			dp[i][j] = max(dp[i - 1][j] + status[i][j], dp[i][j - 1] + status[i][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + status[i][j]);
		}
	}

	cout << dp[n][m];
}