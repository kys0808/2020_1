#include <iostream>
#include <vector>
using namespace std;

int n, m;
int check[9];
vector<int> answer;

void dfs(int start){
	if (answer.size() == m){
		for (int i = 0; i < answer.size(); i++){
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++){
		if (!check[i]){
			check[i] = 1;
			answer.push_back(i);
			dfs(i);
			answer.pop_back();
			check[i] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dfs(1);
}