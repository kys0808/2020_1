#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
int check[10001];

void bfs(int start){
	queue<int> q;
	q.push(start);
	check[start] = 1;
	while (!q.empty()){
		int status = q.front();
		q.pop();
		cout << status << " ";
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
	cout << start << ' ';
	for (int i = 0; i < graph[start].size(); i++){
		int next = graph[start][i];
		if (!check[next])
			dfs(next);
	}
}

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 10001; i++){
		check[i] = 0;
	}
	while (b--){
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
	}
	for (int i = 0; i < 1001; i++){
		sort(graph[i].begin(), graph[i].end());
	}
	bfs(c);
	cout << endl;
	for (int i = 0; i < 10001; i++){
		check[i] = 0;
	}
	dfs(c);
}