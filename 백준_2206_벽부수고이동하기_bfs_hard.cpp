#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
#include <functional>


using namespace std;


int st[1001][1001];
int n, m;
int move_i[4] = { 0, 0, 1, -1 };
int move_j[4] = { 1, -1, 0, 0 };

int check_st[1001][1001][2];	// i,j 벽뿌수기 개수
int answer = 100000001;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++){
			st[i][j] = tmp[j] - '0';
		}
	}
	queue <pair<pair<int, int>, int>> q;	// first는 위치 second는 벽 뿌수기 개수
	q.push({ { 0, 0 }, 0 });
	check_st[0][0][0] = 1;
	while (!q.empty()){
		int c_i = q.front().first.first;
		int c_j = q.front().first.second;
		int c_w = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int next_i = c_i + move_i[i];
			int next_j = c_j + move_j[i];
			if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < m){
				if (!st[next_i][next_j] && !check_st[next_i][next_j][c_w]){	// 벽 아니면
					check_st[next_i][next_j][c_w] = check_st[c_i][c_j][c_w] + 1;
					q.push({ { next_i, next_j }, c_w });
				}
				else{	// 벽이면 깨야지
					if (c_w == 0){
						check_st[next_i][next_j][c_w+1] = check_st[c_i][c_j][c_w]+1;
						q.push({ { next_i, next_j }, c_w+1 });
					}
				}
			}
		}
	}
	if (check_st[n - 1][m - 1][0])
		answer = min(answer, check_st[n - 1][m - 1][0]);
	if (check_st[n - 1][m - 1][1])
		answer = min(answer, check_st[n - 1][m - 1][1]);
	if (answer == 100000001){
		answer = -1;
		cout << answer << endl;
		return 0;
	}
	printf("%d\n", answer);
}