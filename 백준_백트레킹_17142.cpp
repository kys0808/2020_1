#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int st[51][51];	// 상태
int dist[51][51];	// 거리저장용
int check[51][51];	// 방문체크용
int answer = 9999;
int n, m;

vector<pair<int, int>> virus;	// 바이러스 전체
vector<pair<int, int>> active;	// 활성화 된 바이러스
int re_active[11];	// 백트레킹용
int tmp[51][51];	// 백트레킹 마다 거리재기용

int move_i[4] = { 0, 0, 1, -1 };
int move_j[4] = { 1, -1, 0, 0 };
vector<int> pos;

void bfs(){
	memset(check, 0, sizeof(check));
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp[i][j] = dist[i][j];
		}
	}
	queue<pair<int, int>>q;
	for (int i = 0; i < active.size(); i++){
		q.push({ active[i].first, active[i].second });
		tmp[active[i].first][active[i].second] = -3;	// 활성화는 -3
	}

	int time = 0;
	while (!q.empty()){
		int size = q.size();
		time++;	// 시간 증가
		while (size--){
			int c_i = q.front().first;
			int c_j = q.front().second;
			q.pop();
			check[c_i][c_j] = 1;
			for (int i = 0; i < 4; i++){
				int next_i = c_i + move_i[i];
				int next_j = c_j + move_j[i];
				if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < n){
					if (!check[next_i][next_j] && dist[next_i][next_j] != -2){	// 방문 안했던 곳이고 벽이 아니고 바이러스도 아니면
						check[next_i][next_j] = 1;
						q.push({ next_i, next_j });
						if (dist[next_i][next_j] != -1)
						tmp[next_i][next_j] = time;
					}
				}
			}
		}
	}

	int tmp_answer = 0;
	int check_zero = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (tmp[i][j] == 0){
				check_zero++;
			}
			if (tmp[i][j] == -3){
				check_zero++;
			}
			tmp_answer = max(tmp_answer, tmp[i][j]);
		}
	}

	if (check_zero == m){	// 완전히 다 퍼졌으면 answer 갱신
		answer = min(tmp_answer, answer);
	}
}


void back(int depth,int index){
	if (depth == m){	// active 다 채우면 bfs 진행
		bfs();
		return;
	}
	for (int i = index; i < virus.size(); i++){
		if (!re_active[i]){
			re_active[i] = 1;
			pos.push_back(i);
			active.push_back({ virus[i].first, virus[i].second });
			back(depth + 1,i+1);
			active.pop_back();
			pos.pop_back();
			re_active[i] = 0;
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> st[i][j];
			if (st[i][j] == 1){	// 벽이면 dist 에서도 -2로 표시
				dist[i][j] = -2;	// -2 면 벽
			}
			if (st[i][j] == 2){	// 바이러스면 
				dist[i][j] = -1;	// -1이면 바이러스
				virus.push_back({ i, j });
			}
		}
	}
	back(0,0);
	if (answer == 9999){
		cout << -1 << endl;
	}
	else
	cout << answer << endl;
}