#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> num;
vector<int> answer;
int check[10001];
void dfs(){
	if (answer.size() == m){
		for (auto x : answer){
			cout << x << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < num.size(); i++){
		if (!check[num[i]]){
			answer.push_back(num[i]);
			check[num[i]] = 1;
			dfs();
			check[num[i]] = 0;
			answer.pop_back();
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
	dfs();
}