#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int n, m, k;
int start;
vector<int> graph[300001];
int check[300001];



void bfs(int start){
	queue<int> q;
	q.push(start);
	check[start] = 1;
	while (!q.empty()){
		int current = q.front();
		q.pop();
		for (int i = 0; i < graph[current].size(); i++){
			int next = graph[current][i];
			if (check[next] == 0){
				check[next] = check[current] + 1;
				q.push(next);
			}
		}
	}
}

int main(){
	cin >> n >> m >> k >> start;
	for (int i = 0; i < m; i++){
		int s;
		int e;
		cin >> s >> e;
		graph[s].push_back(e);
	}
	bfs(start);
	int count = 0;
	for (int i = 1; i <= n; i++){
		if (check[i] - 1 == k){
			count++;
			cout << i << endl;
		}
	}
	if (count == 0){
		cout << -1 << endl;
		return 0;
	}

}