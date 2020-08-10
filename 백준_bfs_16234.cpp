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
	// ���������� �α����� ���, ���� �����ϸ� ť�� �ְ� �� ���
	// �ѹ��� ó�� �� answer ++;
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
				queue<pair<int, int>> current_status;	// ���� �����ִ°� ��ǥ ����
				current_status.push({ i, j });
				int total_popular = arr[i][j];	// ���� ��ġ ���� ����
				int total_country = 1;							// ���� ��ġ ���� ����
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
								sub = abs(arr[current_i][current_j] - arr[next_i][next_j]);	// ���� ���� �α�����
								if (sub >= l && sub <= r){	// ���� �����ϸ� �� ����
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
				if (current_status.size() > 1){	// ���� �����ִ°��� ������ answer �߰��ؾ���
					end = false;
					while (!current_status.empty()){	// ���� ���� �ִ°��� �ѹ濡 ��� ����
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