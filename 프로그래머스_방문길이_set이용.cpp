#include <string>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int move_i[4] = {0,0,-1,1};
int move_j[4] = {1,-1,0,0};
int check[11][11][11][11];

set<pair<pair<int,int>,pair<int,int>>> real;

int solution(string dirs) {
	int answer = 0;
	int c_i = 5;
	int c_j = 5;
	for (int i = 0; i < dirs.size(); i++){
		char order = dirs[i];
		int n_i, n_j;
		if (order == 'U'){
			n_i = c_i + move_i[0];
			n_j = c_j + move_j[0];
		}
		else if (order == 'D'){
			n_i = c_i + move_i[1];
			n_j = c_j + move_j[1];
		}
		else if (order == 'L'){
			n_i = c_i + move_i[2];
			n_j = c_j + move_j[2];
		}
		else if (order == 'R'){
			n_i = c_i + move_i[3];
			n_j = c_j + move_j[3];
		}
		if (n_i >= 0 && n_j >= 0 && n_i <= 10 && n_j <= 10){
			pair<int, int> tmp_f;
			tmp_f.first = c_i; tmp_f.second = c_j;
			pair<int, int> tmp_s;
			tmp_s.first = n_i; tmp_s.second = n_j;
			real.insert({ tmp_f, tmp_s });
			real.insert({ tmp_s, tmp_f });
			if (check[c_i][c_j][n_i][n_j] == 0 && check[n_i][n_j][c_i][c_j] == 0){
				check[c_i][c_j][n_i][n_j] = 1;
				check[n_i][n_j][c_i][c_j] = 1;
			}
			c_i = n_i; c_j = n_j;
		}
	}
	for (int i = 0; i <= 10; i++){
		for (int j = 0; j <= 10; j++){
			for (int k = 0; k <= 10; k++){
				for (int l = 0; l <= 10; l++){
					if (check[i][j][k][l] == 1){
						answer++;
					}
				}
			}
		}
	}
	answer = real.size();
	answer /= 2;
	return answer;
}

int main(){
	string dirs = "ULURRDLLU";
	solution(dirs);

}