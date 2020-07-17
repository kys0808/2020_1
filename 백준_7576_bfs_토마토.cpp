#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int a, b;
int tomato[1001][1001];
int check[1001][1001];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int day = 0;
int one = 0;
vector<pair<int, int>> start_one;

void bfs(){
	queue<pair<int, int>> q;
	int start_i, start_j;
	for (int i = 0; i < start_one.size(); i++){
		// starting point 모두 queue에 저장
		start_i = start_one[i].first;
		start_j = start_one[i].second;
		q.push(make_pair(start_i, start_j));
		check[start_i][start_j] = 1;
	}
	while (!q.empty()){
		int p_i = q.front().first;
		int p_j = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int n_i = p_i + dx[i];
			int n_j = p_j + dy[i];
			if (n_i >= 0 && n_j >= 0 && n_i < b &&n_j < a){
				if (!check[n_i][n_j] && tomato[n_i][n_j] == 0){
					q.push(make_pair(n_i, n_j));
					tomato[n_i][n_j] = 1;
					check[n_i][n_j] = check[p_i][p_j] + 1;
				}
				if (day < check[n_i][n_j])
					day = check[n_i][n_j];
			}
		}
	}
}
int main(){
	cin >> a >> b;
	for (int i = 0; i < b; i++){
		for (int j = 0; j < a; j++){
			cin >> tomato[i][j];
		}
	}
	bool zero = false;
	for (int i = 0; i < b; i++){
		for (int j = 0; j < a; j++){
			if (tomato[i][j] == 0)
				zero = true;
			if (tomato[i][j] == 1){
				start_one.push_back(make_pair(i, j));	// 시작전에 start_point check
			}
		}
	}
	if (zero){	// zero 있으면 진행
		bfs();
		for (int i = 0; i < b; i++){
			for (int j = 0; j < a; j++){
				if (tomato[i][j] == 0){	// bfs 끝냈을때 0 남아있으면 실패 -1
					cout << "-1";
					return 0;
				}
			}
		}
		cout << day - 1;
		return 0;
	}
	else{	// zero 없으면 진행 x
		cout << "0";
		return 0;
	}
}