#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num;
vector<int> answer;
int check[10001];

void dfs(int start){
	if (answer.size() == m){
		for (auto x : answer){
			cout << x << " ";
		}
		cout << "\n";
	}
	for (int i = start; i < num.size(); i++){
		if (!check[num[i]]){
			check[num[i]] = 1;
			answer.push_back(num[i]);
			dfs(i);
			answer.pop_back();
			check[num[i]] = 0;
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	dfs(0);
}