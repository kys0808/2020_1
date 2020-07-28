#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;


int status[101][101];
int check[101][101];
int n;
int move_i[4] = { 0, 0, -1, 1 };
int move_j[4] = { 1, -1, 0, 0 };

int main(){
	cin >> n;
	int max = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin>>status[i][j];
			if (status[i][j] > max){
				max = status[i][j];
			}
		}
	}

	queue<pair<int, int>> tmp;
	int answer = 0;
	for (int i = 0; i <= max; i++){
		memset(check, 0, sizeof(check));
		int max_answer = 0;
		for (int next_i = 0; next_i < n; next_i++){
			for (int next_j = 0; next_j < n; next_j++){
				if (!check[next_i][next_j] && status[next_i][next_j] >i){
					tmp.push(make_pair(next_i, next_j));
					check[next_i][next_j] = 1;
					while (!tmp.empty()){
						int c_i = tmp.front().first;
						int c_j = tmp.front().second;
						tmp.pop();
						for (int j = 0; j < 4; j++){
							int n_i = c_i + move_i[j];
							int n_j = c_j + move_j[j];
							if (n_i >= 0 && n_i < n && n_j >= 0 && n_j < n){
								if (!check[n_i][n_j] && status[n_i][n_j] > i){
									check[n_i][n_j] = 1;
									tmp.push(make_pair(n_i, n_j));
								}
							}
						}
					}
					max_answer++;
				}
			}
		}
		if (max_answer > answer){
			answer = max_answer;
		}
	}
	cout << answer;

}