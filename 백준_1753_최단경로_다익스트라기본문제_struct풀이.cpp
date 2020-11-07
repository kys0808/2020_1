#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, start_num;

struct N{
	int num;
	int cost;
};
bool operator <(N a, N b){
	if (a.cost < b.cost){
		return true;
	}
	else{
		return false;
	}
}
priority_queue<N> pq;
vector<pair<int, int>> graph[20001];
int dist[20001];

#define MAX_DIST 999999999

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> start_num;
	for (int i = 0; i < m; i++){
		int v, e, dist;
		cin >> v >> e >> dist;
		graph[v].push_back({ dist, e });
	}
	for (int i = 1; i <= n; i++){
		dist[i] = MAX_DIST;
	}
	N newN;
	newN.cost = 0;
	newN.num = start_num;
	pq.push(newN);
	dist[start_num] = 0;
	while (!pq.empty()){
		int current = pq.top().num;
		int cost = -1 * pq.top().cost;
		pq.pop();
		for (int i = 0; i < graph[current].size(); i++){
			int next = graph[current][i].second;
			int ncost = graph[current][i].first;
			if (dist[next] > cost + ncost){
				dist[next] = cost + ncost;
				newN.cost = -dist[next];
				newN.num = next;
				pq.push(newN);
			}
		}
	}
	for (int i = 1; i <= n; i++){
		if (dist[i] == MAX_DIST){
			cout << "INF" << endl;
		}
		else{
			cout << dist[i] << endl;
		}
	}
}