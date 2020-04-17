#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int check[200002];
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int size = n;
		int a;
		int hi = 0;
		int over = 0;
		for (int i = 1; i <= size; i++)
			check[i] = 0;
		while (n--){
			cin >> a;
			check[a]++;
		}
		for (int i = 1; i <= size; i++){
			if (check[i])
				hi++;			// ต๎ภๅ วัณ๐ต้
			if (check[i] > over)
				over = check[i];
		}
		cout <<max(min(hi - 1, over), min(hi, over - 1))<<endl;
	}
}