#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


int n, m;
int status[301][301];
int check[301][301];
int move_i[4] = {0,0,1,-1};
int move_j[4] = {1,-1,0,0};
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> status[i][j];
		}
	}
	queue<pair<int, int>> tmp;
	int year = 0;
	while (1){
		memset(check, 0, sizeof(check));
		int cnt = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (!check[i][j] && status[i][j]){
					tmp.push(make_pair(i, j));
					cnt++;
				}
				while (!tmp.empty()){
					int c_i = tmp.front().first;
					int c_j = tmp.front().second;
					tmp.pop();
					for (int k = 0; k < 4; k++){
						int n_i = c_i + move_i[k];
						int n_j = c_j + move_j[k];
						if (n_i >= 0 && n_i < n && n_j >= 0 && n_j < m){
							if (!check[n_i][n_j] && status[n_i][n_j]){
								tmp.push(make_pair(n_i, n_j));
								check[n_i][n_j] = 1;
							}
						}
					}
				}
			}
		}

		if (cnt >= 2){
			break;
		}

		bool zero = true;
		int tmp[301][301];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				tmp[i][j] = status[i][j];
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (status[i][j]){
					zero = false;
					for (int k = 0; k < 4; k++){
						int n_i = i + move_i[k];
						int n_j = j + move_j[k];
						if (n_i >= 0 && n_i < n && n_j >= 0 && n_j < m){
							if (status[n_i][n_j] == 0 && tmp[i][j]>0){
								tmp[i][j]--;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				status[i][j] = tmp[i][j];
			}
		}
		if (zero && cnt<2){
			year = 0;
			break;
		}
		year++;
	}
	cout << year;
}