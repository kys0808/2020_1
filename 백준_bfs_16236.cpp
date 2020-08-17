#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;


int n;
int move_i[4] = { 0, 0, -1, 1 };
int move_j[4] = { 1, -1, 0, 0 };
int st[21][21];
int visit[21][21];
int dist[21][21];
int time;

vector<pair<int, int>> fish;
queue<pair<int, int>> eating;


int main(){
	cin >> n;
	int current_i;
	int current_j;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> st[i][j];
			if (st[i][j] == 9){
				current_i = i;
				current_j = j;
			}
			if (st[i][j] < 9 && st[i][j] >0){
				fish.push_back({ i, j });
			}
		}
	}
	int total_eat = 0;
	int size = 2;
	while (1){
		// 거리 재기
		memset(visit, 0, sizeof(visit));
		memset(dist, 0, sizeof(dist));
		queue<pair<int, int>> q;
		q.push({ current_i, current_j });
		st[current_i][current_j] = 0;
		dist[current_i][current_j] = 0;
		visit[current_i][current_j] = 1;
		while (!q.empty()){
			int c_i = q.front().first;
			int c_j = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++){
				int next_i = c_i + move_i[i];
				int next_j = c_j + move_j[i];
				if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < n){
					if (!visit[next_i][next_j]){
						visit[next_i][next_j] = 1;
						if (st[next_i][next_j] > size){	// 자기보다 크면
							dist[next_i][next_j] = 99;	// 못가!
						}
						else{
							dist[next_i][next_j] = dist[c_i][c_j] + 1;
							q.push({ next_i, next_j });
						}
					}
				}
			}
		}
		int eat = 0;
		for (int i = 0; i < fish.size(); i++){
			int check_i = fish[i].first;
			int check_j = fish[i].second;
			if (st[check_i][check_j] < size && st[check_i][check_j]>0 && dist[check_i][check_j] != 99 && dist[check_i][check_j] != 0){
				eating.push({ check_i, check_j });
				eat++;
			}
		}
		if (eat == 0){
			break;
		}
		// 거리 확인 했으면
		if (eat == 1){
			// 이동 해서 먹기
			int f_i = eating.front().first;
			int f_j = eating.front().second;
			time += dist[f_i][f_j];
			eating.pop();
			st[f_i][f_j] = 0;
			current_i = f_i;
			current_j = f_j;
			total_eat++;
		}
		if (eat > 1){
			int m_i = 21;	//최단 위치 저장용
			int m_j = 21;	// 최단 거리 위치 저장용
			int m_dist = 99999;
			vector<pair<int, int>> m_fish;
			while(!eating.empty()){
				int f_i = eating.front().first;
				int f_j = eating.front().second;
				if (m_dist > dist[f_i][f_j]){
					// 최단 거리 갱신
					m_dist = dist[f_i][f_j];
					m_fish.push_back({ f_i, f_j });
				}
				eating.pop();
			}
			sort(m_fish.begin(), m_fish.end());	// 최단거리인 것들 중에서
			for (int i = 0; i < m_fish.size(); i++){
				int f_i = m_fish[i].first;
				int f_j = m_fish[i].second;
				if (dist[f_i][f_j] == m_dist){
					m_i = f_i;
					m_j = f_j;
				}
			}
			m_fish.clear();
			// 최단 위치 나왔으니까 거길로 가라
			time += dist[m_i][m_j];
			st[m_i][m_j] = 0;
			total_eat++;
			current_i = m_i;
			current_j = m_j;
		}
		//cout << "먹은양" << endl;
		//cout << total_eat << " " << size << endl;
		if (total_eat == size){
			size++;
			total_eat = 0;
		}
	}
	cout << time << endl;
}