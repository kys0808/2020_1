#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[10001][3];	// 포도주 누적
int st[10001];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> st[i];
	}
	dp[0][0] = 0; 
	dp[0][1] = st[0]; 
	dp[0][2] = 0;
	dp[1][0] = dp[0][1]; 
	dp[1][1] = dp[0][0] + st[1]; 
	dp[1][2] = dp[0][1] + st[1];
	for (int i = 2; i < n; i++){
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = max(dp[i - 1][0] + st[i], dp[i - 1][1]);
		dp[i][2] = max(dp[i - 1][1] + st[i], dp[i - 1][2]);
	}
	int answer = 0;
	for (int i = 0; i < 3; i++){
		answer = max(dp[n - 1][i], answer);
	}
	cout << answer;
}