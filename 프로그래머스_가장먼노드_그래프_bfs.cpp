#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

vector<int>graph[20001];
int check[20001];
int dist[20001];

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	for (int i = 0; i < edge.size(); i++){
		int start = edge[i][0];
		int end = edge[i][1];
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 0; i <= n; i++){
		dist[i] = 99999;
	}
	queue<int> q;
	q.push(1);
	check[1] = 1;
	int depth = 0;
	while (1){
		int q_size = q.size();
		if (q_size == 0){
			break;
		}
		depth++;
		while (q_size--){
			int current = q.front();
			q.pop();
			for (int i = 0; i < graph[current].size(); i++){
				if (check[graph[current][i]] == 0){
					check[graph[current][i]] = 1;
					dist[graph[current][i]] = depth;
					q.push(graph[current][i]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++){
		if (dist[i] == depth - 1){
			answer++;
		}
	}
	return answer;
}

int main(){
	int n = 6;
	vector<vector<int>> vertex = { { 3, 6 }, { 4, 3 }, { 3, 2 }, { 1, 3 }, { 1, 2 }, { 2, 4 }, { 5, 2 } };
	solution(n, vertex);
}