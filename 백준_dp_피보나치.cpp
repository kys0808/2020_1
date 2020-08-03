#include <iostream>

using namespace std;


int dp[1000001];

int fibo(int n){
	if (n <= 0){
		return 0;
	}
	if (n == 1)
		return 1;
	int answer= fibo(n - 1) + fibo(n - 2);
	return answer;
}

int main(){
	int n;
	cin >> n;
	cout<<fibo(n);

}