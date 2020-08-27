#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int answer;

int st[26][26];
int cost[26][26];
int move_i[4] = { 0, 0, 1, -1 };
int move_j[4] = { 1, -1, 0, 0 };

int solution(vector<vector<int>> board) {

	int n = board.size();
	int m = board[0].size();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cost[i][j] = 999999999;
		}
	}
	queue<pair<pair<pair<int, int>, int>,int>> q; // i,j,dir,cost
	cost[0][0] = 0;
	q.push({ { { 0, 0 }, 10 }, 0 });
	while (!q.empty()){
		int current_i = q.front().first.first.first;
		int current_j = q.front().first.first.second;
		int current_dir = q.front().first.second;
		int current_cost = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++){
			int tmp = 0;
			int next_i = current_i + move_i[k];
			int next_j = current_j + move_j[k];
			if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < m && board[next_i][next_j] == 0){
				if (current_dir == 10 || k == current_dir){
					tmp = current_cost + 100;
				}
				else if (k != current_dir){
					tmp = current_cost + 600;
				}	

				if (cost[next_i][next_j] >= tmp){
					cost[next_i][next_j] = tmp;
					q.push({{ { next_i, next_j }, k }, tmp});
				}
			}
		}
	}
	answer = cost[n - 1][m - 1];

	return answer;
}

int main(){
	vector<vector<int>> board;
	board = { { 0, 0, 0, 0, 0, 0 }, { 0, 1, 1, 1, 1, 0 }, { 0, 0, 1, 0, 0, 0 }, { 1, 0, 0, 1, 0, 1 }, { 0, 1, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0, 0 } };
	solution(board);
}