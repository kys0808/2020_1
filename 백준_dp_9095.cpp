#include <iostream>
using namespace std;

int d[11];
int main(){
	int t, n;
	cin >> t;
	d[0] = 1;
	for (int i = 1; i < 11; i++){
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}
	while (t--){
		cin >> n;
		cout << d[n]<<endl;
	}
}