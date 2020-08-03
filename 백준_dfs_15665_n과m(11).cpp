#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> ans;
vector<int> num;
int check[10001];
int cnt[20][10001];
int n, m;
void dfs(int idx){
	if (ans.size() == m){
		for (auto x : ans)
			cout << x << " ";
		cout << "\n";
		return;
	}
	for (int  i =0; i < num.size(); i++){
		if (!cnt[ans.size()][num[i]]){
			cnt[ans.size()][num[i]] = 1;
			ans.push_back(num[i]);
			dfs(i);
			ans.pop_back();
			check[i] = 0;
		}
	}
	memset(cnt[ans.size()], 0, sizeof(cnt[ans.size()]));
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