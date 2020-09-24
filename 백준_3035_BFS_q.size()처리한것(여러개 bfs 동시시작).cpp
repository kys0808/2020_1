#include <iostream>
#include <string>
#include <queue>

using namespace std;

int r, c;
char st[51][51];
int check_time[51][51];
int check[51][51];
int answer = 0;

int move_i[4] = { 0, 0, 1, -1 };
int move_j[4] = { 1, -1, 0, 0 };

queue<pair<int, int>> w;
queue<pair<int, int>> g;// 고슴도치

int time = 1;

void going(){
	//1) 물채우기
	// 물인곳 체크
	while (1){
		if (time >= 250){
			answer = -1;
			break;
		}
		int w_size = w.size();
		while (w_size--){
			int c_i = w.front().first;
			int c_j = w.front().second;
			w.pop();
			for (int i = 0; i < 4; i++){
				int next_i = c_i + move_i[i];
				int next_j = c_j + move_j[i];
				if (next_i >= 0 && next_j >= 0 && next_i < r && next_j < c){
					if (st[next_i][next_j] == '.'){	// 비어있는곳 물채워
						st[next_i][next_j] = '*';
						w.push({ next_i, next_j });
					}
				}
			}
		}

		/*
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (check[i][j] == time){
					g.push({ i, j });
				}
			}
		}
		*/
		int g_size = g.size();
		while (g_size--){
			int c_i = g.front().first;
			int c_j = g.front().second;
			g.pop();
			if (st[c_i][c_j] == 'D'){
				answer = check[c_i][c_j];
				return;
			}
			for (int i = 0; i < 4; i++){
				int next_i = c_i + move_i[i];
				int next_j = c_j + move_j[i];
				if (next_i >= 0 && next_j >= 0 && next_i < r && next_j < c){
					if (!check[next_i][next_j]){
						if (st[next_i][next_j] == '.' || st[next_i][next_j] == 'D'){
							//check[next_i][next_j] = time + 1;
							check[next_i][next_j] = check[c_i][c_j] + 1;
							g.push({ next_i, next_j });
						}
					}
				}
			}
		}
		time++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++){
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++){
			st[i][j] = tmp[j];
			if (st[i][j] == 'S'){
				g.push({ i, j });
				check[i][j] = 1;
			}
			if (st[i][j] == '*'){
				w.push({ i, j });
			}
		}
	}
	going();
	if (answer == -1){
		cout << "KAKTUS" << endl;
	}
	else{
		cout << answer-1 << endl;
	}
}