#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> num;
vector<int> answer;
int n, m;
int check[10001];
int cnt[20][10001];
void dfs(){
	if (answer.size() == m){
		for (auto x : answer)
			cout << x << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < num.size(); i++){
		if (!check[i] && !cnt[answer.size()][num[i]]){
			check[i] = cnt[answer.size()][num[i]] = 1;
			answer.push_back(num[i]);
			dfs();
			answer.pop_back();
			check[i] = 0;
		}
	}
	memset(cnt[answer.size()], 0, sizeof(cnt[answer.size()]));
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