#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1001];
int answer = 0;
int check[1001];
int cnt[1001];
void dfs(int start,int status){
	if (!check[start]){
		check[start] = status;
		for (int i = 0; i < graph[start].size(); i++){
			dfs(graph[start][i],status);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		dfs(i,i);
	}
	for (int i = 1; i <= n; i++){
		cnt[check[i]]++;
	}
	for (int i =1; i <= n; i++){
		if (cnt[i])
			answer++;
	}
	cout << answer << endl;
}