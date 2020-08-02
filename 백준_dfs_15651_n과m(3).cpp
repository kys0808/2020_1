#include <iostream>
#include <vector>
using namespace std;

int n, m;
int check[9];
vector<int> answer;

void dfs(){
	if (answer.size() == m){
		for (int i = 0; i < answer.size(); i++){
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++){
		answer.push_back(i);
		dfs();
		answer.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dfs();
}