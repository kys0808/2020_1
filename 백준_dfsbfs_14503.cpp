#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int check[51][51];
int status[51][51];
int move_i[4] = {0,1,0,-1};
int move_j[4] = {1,0,-1,0};

int answer = 0;

int main(){
	cin >> n >> m;
	int r, c,d;
	cin >> r >> c >> d; // r,c 위치 d 방향
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> status[i][j];
			if (status[i][j] == 1)
				check[i][j] = 1;
		}
	}
	queue<pair<int, int>> tmp;
	tmp.push(make_pair(r, c));
	int current_d = d-1;
	while (!tmp.empty()){
		int current_i = tmp.front().first;
		int current_j = tmp.front().second;
		tmp.pop();
		if (!check[current_i][current_j]){
			answer++;
			check[current_i][current_j] = 1;
		}
		int cnt = 0;
		while (cnt<4){
			int next_d = (current_d + 3) % 4;
			int next_i = current_i + move_i[next_d];
			int next_j = current_j + move_j[next_d];
			if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < m){
				if (!check[next_i][next_j] && !status[next_i][next_j]){
					tmp.push(make_pair(next_i, next_j));
					current_d = next_d;
					break;
				}
				else{
					cnt++;
					current_d = next_d;
				}
			}
		}
		if (cnt == 4){
			int next_i = current_i - move_i[current_d];
			int next_j = current_j - move_j[current_d];
			if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m){
				if (status[next_i][next_j]){
					break;
				}
				else{
					tmp.push(make_pair(next_i, next_j));
				}
			}
		}
	}
	cout << answer;
}