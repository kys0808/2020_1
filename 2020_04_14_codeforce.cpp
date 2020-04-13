#include <iostream>
using namespace std;

int main(){
	int t;
	int a;
	int b;
	int n;
	int check;
	
	cin >> t;
	while (t--){
		cin >> n;
		a = 0; b = 0; check = 0;
		for (int i = 1; i < n; i++){
			b = i;
			a = n - i;
			if (a > b){
				check++;
			}
		}
		if (check == 0)
			cout << 0<<endl;
		else
			cout << check<<endl;
	}
}