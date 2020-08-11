#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int status[501][501];
int tmp[19];
int answer[19];
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> status[i][j];
		}
	}
	// 가로 1자
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (j + 3 < m){
				tmp[0] = status[i][j] + status[i][j + 1] + status[i][j + 2] + status[i][j + 3];
			}
			answer[0] = max(answer[0], tmp[0]);
			// 세로 1자
			if (i + 3 < n){
				tmp[1] = status[i][j] + status[i + 1][j] + status[i + 2][j] + status[i + 3][j];
			}
			answer[1] = max(answer[1], tmp[1]);
			// 네모 
			if (i + 1 < n && j + 1 < m){
				tmp[2] = status[i][j] + status[i + 1][j] + status[i][j + 1] + status[i + 1][j + 1];
			}
			answer[2] = max(answer[2], tmp[2]);
			// 3번째 -1
			if (i + 2 < n && j - 1 >= 0){
				tmp[3] = status[i][j] + status[i + 1][j] + status[i + 2][j] + status[i + 2][j - 1];
			}
			answer[3] = max(answer[3], tmp[3]);
			if (i + 2 < n && j + 1 < m){
				tmp[4] = status[i][j] + status[i + 1][j] + status[i + 2][j] + status[i + 2][j + 1];
			}
			answer[4] = max(answer[4], tmp[4]);
			if (j - 2 >= 0 && i + 1 < n){
				tmp[5] = status[i][j] + status[i + 1][j] + status[i + 1][j - 1] + status[i + 1][j - 2];
			}
			answer[5] = max(answer[5], tmp[5]);
			if (j + 2 < m && i + 1 < n){
				tmp[6] = status[i][j] + status[i + 1][j] + status[i + 1][j + 1] + status[i + 1][j + 2];
			}
			answer[6] = max(answer[6], tmp[6]);
			if (i + 2 < n && j + 1 < m){
				tmp[7] = status[i][j] + status[i][j + 1] + status[i + 1][j + 1] + status[i + 2][j + 1];
				tmp[8] = status[i][j] + status[i][j + 1] + status[i + 1][j] + status[i + 2][j];
			}
			answer[7] = max(answer[7], tmp[7]);
			answer[8] = max(answer[8], tmp[8]);
			if (j + 2 < m && i + 1 < n){
				tmp[9] = status[i][j] + status[i][j + 1] + status[i][j + 2] + status[i + 1][j + 2];
				tmp[10] = status[i][j] + status[i][j + 1] + status[i][j + 2] + status[i + 1][j];
			}
			answer[9] = max(answer[9], tmp[9]);
			answer[10] = max(answer[10], tmp[10]);
			if (i + 2 < n && j + 1 < m){
				tmp[11] = status[i][j] + status[i + 1][j] + status[i + 1][j + 1] + status[i + 2][j + 1];
				tmp[12] = status[i][j + 1] + status[i + 1][j + 1] + status[i + 1][j] + status[i + 2][j];
			}
			answer[11] = max(answer[11], tmp[11]);
			answer[12] = max(answer[12], tmp[12]);
			if (i + 1 < n && j + 2 < m){
				tmp[13] = status[i][j + 1] + status[i][j + 2] + status[i + 1][j] + status[i + 1][j + 1];
				tmp[14] = status[i][j] + status[i][j + 1] + status[i + 1][j + 1] + status[i + 1][j + 2];
				tmp[15] = status[i][j] + status[i][j + 1] + status[i][j + 2] + status[i + 1][j + 1];
				tmp[16] = status[i][j + 1] + status[i + 1][j] + status[i + 1][j + 1] + status[i + 1][j + 2];
			}
			answer[13] = max(answer[13], tmp[13]);
			answer[14] = max(answer[14], tmp[14]);
			answer[15] = max(answer[15], tmp[15]);
			answer[16] = max(answer[16], tmp[16]);
			if (i + 2 < n && j + 1 < m){
				tmp[17] = status[i][j] + status[i + 1][j] + status[i + 1][j + 1] + status[i + 2][j];
				tmp[18] = status[i + 1][j] + status[i][j + 1] + status[i + 1][j + 1] + status[i + 2][j + 1];
			}
			answer[17] = max(answer[17], tmp[17]);
			answer[18] = max(answer[18], tmp[18]);
		}
	}
	int real_answer = 0;
	for (int i = 0; i < 19; i++){
		real_answer = max(real_answer, answer[i]);
	}
	cout << real_answer;
}