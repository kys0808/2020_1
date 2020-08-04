#include <iostream>
#include <string>
using namespace std;

int n;
long long check[1001][10];
long long answer = 0;

int main(){
	cin >> n;
	for (int i = 0; i < 10; i++){
		check[1][i] = 1;
	}
	if (n == 1){
		for (int i = 0; i < 10; i++){
			answer += check[1][i];
		}
		cout << answer << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++){
		for (int j = 0; j < 10; j++){
			for (int k = j; k < 10; k++){
				check[i][j] += check[i-1][k];
				check[i][j] %= 10007;
			}
		}
	}
	for (int i = 0; i < 10; i++){
		answer += check[n][i];
	}
	cout << (answer%10007);
}