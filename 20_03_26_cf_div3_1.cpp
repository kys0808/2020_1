#include <iostream>
using namespace std;

int main(){
	int a; int b;
	int t;
	cin >> t;
	while (t--){
		cin >> a >> b;
		int check = a%b;
		if (!check)
			cout << 0 << endl;
		else{
			cout << (b - check) << endl;;
		}
	}
}