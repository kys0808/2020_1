#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[51];
#define MAX_COST 99999999

bool check[51];
int dist[51];

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	int tmp_dist[51][51];
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			tmp_dist[i][j] = MAX_COST;
		}
	}

	for (int i = 0; i < road.size(); i++){
		int a = road[i][0];
		int b = road[i][1];
		int cost = road[i][2];
		tmp_dist[a][b] = min(tmp_dist[a][b], cost);
		tmp_dist[b][a] = min(tmp_dist[b][a], cost);
	}
	for (int i = 1; i <= N; i++){
		for (int j = i + 1; j <= N; j++){
			if (i != j){
				if (tmp_dist[i][j] != MAX_COST){
					graph[i].push_back({ tmp_dist[i][j], j });
					graph[j].push_back({ tmp_dist[j][i], i });
				}
			}
		}
	}
	for (int i = 1; i <= N; i++){
		dist[i] = MAX_COST;
	}
	priority_queue < pair<int, int> > pq;

	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty()){
		int current = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[current].size(); i++){
			int next = graph[current][i].second;
			int ncost = graph[current][i].first;
				if (dist[next] > cost + ncost){
					dist[next] = cost + ncost;
					pq.push({ -dist[next], next });
				}
			}
	}
	for (int i = 1; i <= N; i++){
		if (dist[i] <= K){
			answer++;
		}
	}
	return answer;
}