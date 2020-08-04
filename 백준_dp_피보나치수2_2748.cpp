#include <iostream>

using namespace std;

long long check[91];
long long answer = 0;
long long fibo(long long n){
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	long long &ret = check[n];
	if (ret) return ret;
	ret = fibo(n - 1) + fibo(n - 2);

}

int main(){
	int n;
	cin >> n;
	check[0] = 0;
	check[1] = 1;
	for (int i = 2; i <= n; i++){
		check[i] = check[i - 1] + check[i - 2];
	}
	cout << check[n];
}