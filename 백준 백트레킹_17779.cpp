#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


int n;
int people[21][21];
int state[21][21];
int check[21][21];
int move_i[4] = { 0, 0, 1, -1 };
int move_j[4] = { 1, -1, 0, 0 };
int answer = 9999;
void going_state(int x, int y, int d1, int d2){
	memset(state, 0, sizeof(state));
	memset(check, 0, sizeof(check));
	if (d1 >= 1 && d2 >= 1){
		if (1 <= x && x < x + d1 + d2 && x + d1 + d2 <= n){
			if (1 <= y - d1 && y - d1 < y && y < y + d2 && y + d2 <= n){
				// 5번 지역구 경계잡기


				int first_i = x;
				int first_j = y;
				while (first_i <= (x + d1) && first_j >= (y - d1)){
					if (!check[first_i][first_j]){
						check[first_i][first_j] = 1;
						state[first_i][first_j] = 5;
						first_i += 1;
						first_j -= 1;
					}
				}
				first_i = x;
				first_j = y;
				while (first_i <= (x + d2) && first_j <= (y + d2)){
						check[first_i][first_j] = 1;
						state[first_i][first_j] = 5;
						first_i += 1;
						first_j += 1;
				}
				first_i = x + d1;
				first_j = y - d1;
				while (first_i <= (x + d1 + d2) && first_j <= (y - d1 + d2)){
						check[first_i][first_j] = 1;
						state[first_i][first_j] = 5;
						first_i += 1;
						first_j += 1;
				}
				first_i = x + d2;
				first_j = y + d2;
				while (first_i <= (x + d2 + d1) && first_j >= (y + d2 - d1)){
					check[first_i][first_j] = 1;
					state[first_i][first_j] = 5;
					first_i += 1;
					first_j -= 1;
				}

				// 1번 지역구 만들기
				for (int i = 1; i < x + d1; i++){
					for (int j = 1; j <= y; j++){
						if (state[i][j] != 5){
							if (!check[i][j]){
								check[i][j] = 1;
								state[i][j] = 1;
							}
						}
						else{
							break;
						}
					}
				}
				// 2번 지역구 만들기
				for (int i = x + d2; i >= 1; i--){
					for (int j = n; j >= y; j--){
						if (state[i][j] != 5){
							if (!check[i][j]){
								check[i][j] = 1;
								state[i][j] = 2;
							}
						}
						else{
							break;
						}
					}
				}
				// 3번 지역구 만들기
				for (int i = x + d1; i <= n; i++){
					for (int j = 1; j < y - d1 + d2; j++){
						if (state[i][j] != 5){
							if (!check[i][j]){
								check[i][j] = 1;
								state[i][j] = 3;
							}
						}
						else{
							break;
						}
					}
				}
				// 4번 지역구 만들기
				for (int i = n; i >=x + d2 + 1; i--){
					for (int j = n; j >= y - d1 + d2; j--){
						if (state[i][j] != 5){
							if (!check[i][j]){
								check[i][j] = 1;
								state[i][j] = 4;
							}
						}
						else{
							break;
						}
					}
				}
				for (int i = 1; i <= n; i++){
					for (int j = 1; j <= n; j++){
						if (!check[i][j]){
							if (!state[i][j]){
								state[i][j] = 5;
							}
						}
					}
				}

				
				// 이제 인구세자
				int check_people[6];	// 5개 지역구
				memset(check_people, 0, sizeof(check_people));
				for (int i = 1; i <= n; i++){
					for (int j = 1; j <= n; j++){
						check_people[state[i][j]] += people[i][j];
					}
				}

				int max_people = 0;
				int min_people = 99999;
				for (int i = 1; i < 6; i++){
					max_people = max(max_people, check_people[i]);
					min_people = min(min_people, check_people[i]);
				}
				answer = min(answer, (max_people - min_people));
			}
		}
	}
}

vector<int> tmp;
void back(int depth){
	if (depth == 4){
		going_state(tmp[0], tmp[1], tmp[2], tmp[3]);
		return; 
	}
	for (int i = 1; i <= n; i++){
		tmp.push_back(i);
		back(depth + 1);
		tmp.pop_back();
	}
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> people[i][j];
		}
	}
	back(0);
	cout << answer << endl;
}