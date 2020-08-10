#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


int arr[101][101];
int real_arr[101][101];
int check[101][101];
int n, l, r;
int answer = 0;
int move_i[4] = { 0, 0, -1, 1 };
int move_j[4] = { 1, -1, 0, 0 };

int main(){
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> real_arr[i][j];
		}
	}
	// 시작점에서 인구차이 계산, 조건 만족하면 큐에 넣고 또 계산
	// 한번에 처리 후 answer ++;
	while (1){
		bool end = true;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				arr[i][j] = real_arr[i][j];
			}
		}
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				queue<pair<int, int>> bfs;
				bfs.push({ i, j });
				check[i][j] = 1;
				queue<pair<int, int>> current_status;	// 국경 열려있는곳 좌표 저장
				current_status.push({ i, j });
				int total_popular = arr[i][j];	// 현재 위치 나라 기준
				int total_country = 1;							// 현재 위치 나라 기준
				while (!bfs.empty()){
					int current_i = bfs.front().first;
					int current_j = bfs.front().second;
					bfs.pop();
					for (int k = 0; k < 4; k++){
						int next_i = current_i + move_i[k];
						int next_j = current_j + move_j[k];
						if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < n){
							int sub = 0;
							if (!check[next_i][next_j]){
								sub = abs(arr[current_i][current_j] - arr[next_i][next_j]);	// 인접 국가 인구차이
								if (sub >= l && sub <= r){	// 조건 만족하면 문 열어
									total_popular += arr[next_i][next_j];
									total_country += 1;
									check[next_i][next_j] = 1;
									bfs.push({ next_i, next_j });
									current_status.push({ next_i, next_j });
								}
							}
						}
					}
				}
				if (current_status.size() > 1){	// 국경 열려있는곳이 있으면 answer 추가해야지
					end = false;
					while (!current_status.empty()){	// 국경 열려 있는곳들 한방에 묶어서 갱신
						int re_i = current_status.front().first;
						int re_j = current_status.front().second;
						current_status.pop();
						int new_arr = total_popular / total_country;
						real_arr[re_i][re_j] = new_arr;
					}
				}
			}
		}
		if (end == false){
			answer++;
		}
		if (end == true){
			break;
		}
	}
	cout << answer;
}