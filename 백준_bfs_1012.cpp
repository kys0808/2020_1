#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int m, n, k;

int status[51][51];
int check[51][51];
int move_i[4] = { 0, 0, 1, -1 };
int move_j[4] = { -1, 1, 0, 0 };
int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> m >> n >> k;
		memset(check, 0, sizeof(check));
		memset(status, 0, sizeof(status));
		for (int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			status[y][x] = 1;
		}
		queue<pair<int, int>> tmp;
		int answer = 0;
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= m; j++){
				if (status[i][j] && !check[i][j]){
					tmp.push(make_pair(i, j));
					check[i][j] = 1;
					while (!tmp.empty()){
						int current_i = tmp.front().first;
						int current_j = tmp.front().second;
						tmp.pop();
						for (int k = 0; k < 4; k++){
							int next_i = current_i + move_i[k];
							int next_j = current_j + move_j[k];
							if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m){
								if (!check[next_i][next_j] && status[next_i][next_j]){
									check[next_i][next_j] = 1;
									tmp.push(make_pair(next_i, next_j));
								}
							}
						}
					}
					answer++;
				}
			}
		}
		cout << answer << endl;
	}
}