#include <iostream>

using namespace std;

int n;
long long dp[91][2];
long long answer = 0;
int main(){
	cin >> n;
	dp[1][0] = 0; dp[1][1] = 1;
	for (int i = 2; i <= n; i++){
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	answer = dp[n][0] + dp[n][1];
	cout << answer;
}