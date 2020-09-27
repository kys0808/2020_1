#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;


int n, m;
vector < pair<int, int> >graph[20001];
int dist[20001];
// 다익스트라 (pq이용)
// O(E*logN)	E :간선 N: 정점

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int start;
	//cin >> n >> m;
	//cin >> start;
	scanf("%d %d", &n, &m);
	scanf("%d", &start);

	//1) 그래프 노드 연결과 비용 입력
	for (int i = 0; i < m; i++){
		int u, v, w;
		//cin >> u >> v >> w;
		scanf("%d %d %d", &u, &v, &w);
		// u-> v로 가는데 비용 w
		graph[u].push_back({ w, v });
	}
	//2) node 번호의 비용 초기화
	for (int i = 1; i <= n; i++){
		dist[i] = 99999999;
	}

	//3) pq 사용 <-cost, node_num> ㄴ
	//	-cost를 입력하는 이유는 pq는 내림차순으로 정렬하는것이 기본이다. 따라서 비용을 기준으로 가장 적은비용 정렬하기 위해
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });	// 시작점, 비용은 0
	dist[start] = 0;		// 시작점의 비용은 0

	while (!pq.empty()){
		int current = pq.top().second;
		int cost = -1*pq.top().first;	// 비용 음수이기 때문에 -1처리
		pq.pop();
		for (int i = 0; i < graph[current].size(); i++){
			int next = graph[current][i].second;
			int ncost = graph[current][i].first;
			if (dist[next] > cost + ncost){	// 기존의 비용보다 더 적은 비용이 존재하면 갱신 후 pq입력
				dist[next] = cost + ncost;
				pq.push({ -1 * dist[next], next });
			}
		}
	}

	for (int i = 1; i <= n; i++){
		if (dist[i] == 99999999){
			printf("INF\n");
		}
		else{
			printf("%d\n", dist[i]);
		}
	}


}