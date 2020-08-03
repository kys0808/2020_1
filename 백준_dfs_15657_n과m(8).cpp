#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
vector<int> answer;
int n, m;

void dfs(int start){
	if (answer.size() == m){
		for (auto x : answer)
			cout << x << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < num.size(); i++){
		if (num[i]<start)continue;
		answer.push_back(num[i]);
		dfs(num[i]);
		answer.pop_back();
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
	dfs(num[0]);
}