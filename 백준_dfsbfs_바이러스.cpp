#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> graph[101];
int check[101];
int answer = 0;

void bfs(int start){
	queue<int> q;
	q.push(start);
	check[start] = 1;
	while (!q.empty()){
		int status = q.front();
		q.pop();
		answer++;
		for (int i = 0; i < graph[status].size(); i++){
			int next = graph[status][i];
			if (!check[next]){
				q.push(next);
				check[next] = 1;
			}
		}
	}
}
void dfs(int start){
	check[start] = 1;
	for (int i = 0; i < graph[start].size();i++){
		int next = graph[start][i];
		if (!check[next]){
			answer++;
			dfs(next);
		}
	}
}

int main(){
	int a, b;
	cin >> a >> b;
	while (b--){
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	//dfs(1);
	bfs(1);
	cout << answer-1;
}
