#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dist[101][101];
#define MAX_DIST 99999;

// 플로이드 - 모든노드<-> 모든노드 사이의 최단경로를 구하라
// 특히 중간 경유지를 포함해서 최단경로를 갱신하는 방식 
// 3중 for문 이기때문에 O(V^3)	// 정점기준 3중첩 (k,i,j ==> min(dist[i][j], dist[i][k]+dist[k][j])

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	// 1) 간선 가중치 초기화
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dist[i][j] = 0;
		}
	}
	// 2) 간선 가중치 부여
	for (int i = 0; i < results.size(); i++){
		int win = results[i][0];
		int lose = results[i][1];
		dist[win][lose] = 1;
	}

	// 3) 플로이드 시작
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (dist[i][k] && dist[k][j]){
					dist[i][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++){
		int count = 0;
		for (int j = 1; j <= n; j++){
			if (dist[i][j] || dist[j][i]){	// 둘중 하나라도 이겼으면 승패가 확실하다
				count++;
			}
		}
		if (count == n - 1){
			answer++;
		}
	}
	cout << answer << endl;
	return answer;
}

int main(){
	int n = 5;
	vector<vector<int>> results = { { 4, 3 }, { 4, 2 }, { 3, 2 }, { 1, 2 }, { 2, 5 } };
	solution(n, results);
}