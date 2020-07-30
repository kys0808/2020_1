#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int row, col;
int check[9][9];
int status[9][9];
int copy_status[9][9];
int move_i[4] = { 0, 0, 1, -1 };
int move_j[4] = { 1, -1, 0, 0 };
int max_cnt = 0;

int main(){
	cin >> row >> col;
	int zerocount = 0;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			int tmp;
			cin >> tmp;
			status[i][j] = tmp;
			if (tmp == 0)
				zerocount++;
		}
	}
	if (zerocount == 3){
		cout << 0;
		return 0;
	}
	for (int a = 0; a < row; a++){
		for (int b = 0; b < col; b++){
			for (int c = 0; c < row; c++){
				for (int d = 0; d < col; d++){
					for (int e =0; e < row; e++){
						for (int f = 0; f < col; f++){
							memset(check, 0, sizeof(check));
							memset(copy_status, 0, sizeof(copy_status));
							queue<pair<int, int>> q;
							for (int i = 0; i < row; i++){	// status copy
								for (int j = 0; j < col; j++){
									copy_status[i][j] = status[i][j];
								}
							}
							if ((a == c && b == d) || (a == e && b == f) || (c == e && d == f)){	// 벽세울 좌표 같으면 pass
								continue;
							}
							else if(copy_status[a][b] == 2 || copy_status[c][d] == 2 || copy_status[e][f] == 2 || copy_status[a][b] == 1 || copy_status[c][d] == 1 || copy_status[e][f] == 1)
								continue;
							// 벽 세울 좌표에 바이러스나 이미 벽이 있으면 pass 
							else{	// 벽세우기
								copy_status[a][b] = 1;
								copy_status[c][d] = 1;
								copy_status[e][f] = 1;
								//bfs 시작
								for (int i = 0; i < row; i++){
									for (int j = 0; j < col; j++){
										if (copy_status[i][j] == 2){
											if (check[i][j] == 0){
												check[i][j] = 1;
												q.push(make_pair(i, j));
											}
										}
										while (!q.empty()){
											int current_i = q.front().first;
											int current_j = q.front().second;
											q.pop();
											for (int index = 0; index < 4; index++){
												int new_i = current_i + move_i[index];
												int new_j = current_j + move_j[index];
												if (new_i >= 0 && new_j >= 0 && new_i < row && new_j < col){
													if (check[new_i][new_j] == 0){
														if (copy_status[new_i][new_j] == 0){
															check[new_i][new_j] = 1;
															copy_status[new_i][new_j] = 2;
															q.push(make_pair(new_i, new_j));
														}
													}
												}
											}
										}
									}
								}
								int cnt = 0;
								for (int i = 0; i < row; i++){
									for (int j = 0; j < col; j++){
										if (copy_status[i][j] == 0){
											cnt++;
										}
									}
								}
								if (cnt > max_cnt){
									max_cnt = cnt;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << max_cnt;
}