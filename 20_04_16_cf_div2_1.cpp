#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	int n; int k;
	int u; int v;
	cin >> n >> k;
	int t = n - 1;
	vector<int>* node;
	vector<int> num;

	while (t--){
		cin >> u >> v;
		node[u].push_back(v);
	}
	for (int i = 1; i < n; i++){
		if (node[i].empty()){
			num.push_back(i);
		}
	}

}