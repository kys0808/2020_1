#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int st[51][51];	// 집 정보
int chicken[51][51];	 // 치킨거리 갱신용
int check[51][51];		// 방문 정보
vector<pair<int,int>> tmp;	// 치킨집 저장용
int move_i[4] = { 0, 0, -1, 1 };
int move_j[4] = { 1, -1, 0, 0 };

int restart_check[51][51];
vector<int> answer;

/*
void bfs(){
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			chicken[i][j] = 99999;
		}
	}
	for (int i = 0; i < m; i++){
		memset(check, 0, sizeof(check));
		q.push({ tmp[i].first,tmp[i].second });	
		// 치킨집 순서대로 진행
		check[tmp[i].first][tmp[i].second] = 1;
		int distance = 0;
		chicken[tmp[i].first][tmp[i].second] = distance;
		while (!q.empty()){
			int current_i = q.front().first;
			int current_j = q.front().second;
			q.pop();
			distance = chicken[current_i][current_j]+1;
			for (int j = 0; j < 4; j++){
				int next_i = current_i + move_i[j];
				int next_j = current_j + move_j[j];
				if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < n){
					if (!check[next_i][next_j]){
						q.push({ next_i, next_j });
						chicken[next_i][next_j] = min(distance,chicken[next_i][next_j]);
						// 치킨집마다 bfs진행했을때, 각각에서의 최소거리만 갱신
						check[next_i][next_j] = 1;
					}
				}
			}
		}
		int tmp_answer = 0;
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				if (st[j][k] == 1){
					tmp_answer += chicken[j][k];
				}
			}
		}
		answer.push_back(tmp_answer);
	}
}
*/

void bfs(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			chicken[i][j] = 9999;
		}
	}
	for (int i = 0; i < m; i++){
		int r1 = tmp[i].first;
		int c1 = tmp[i].second;
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				if (st[j][k] == 1){
					int r2 = j;
					int c2 = k;
					chicken[j][k] = min((abs(r1 - r2) + abs(c1 - c2)),chicken[j][k]);
				}
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (st[i][j] == 1)
				result += chicken[i][j];
		}
	}
	answer.push_back(result);
}

void dfs(int start_i, int start_j){
	if (tmp.size() == m){
		/*
		cout << "dfs start" << endl;
		for (int i = 0; i < m; i++){
			cout << tmp[i].first << " " << tmp[i].second << endl;
		}
		*/
		bfs();
		return;
	}
	for (int i = start_i; i < n; i++){
		for (int j = 0; j < n; j++){
			if (st[i][j] == 2 && !restart_check[i][j]){
				restart_check[i][j] = 1;
				tmp.push_back({ i, j });
				dfs(i,j);
				tmp.pop_back();
				restart_check[i][j] = 0;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> st[i][j];
		}
	}
	dfs(0,0);
	sort(answer.begin(), answer.end());
	cout << answer[0];
}