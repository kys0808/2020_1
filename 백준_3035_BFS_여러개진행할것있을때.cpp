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
queue<pair<int, int>> g;// ����ġ

int time = 1;

void going(){
	//1) ��ä���
	// ���ΰ� üũ
	while (1){
		if (time >= 250){
			answer = -1;
			break;
		}
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (st[i][j] == '*'){
					w.push({ i, j });
				}
			}
		}
		while (!w.empty()){
			int c_i = w.front().first;
			int c_j = w.front().second;
			w.pop();
			for (int i = 0; i < 4; i++){
				int next_i = c_i + move_i[i];
				int next_j = c_j + move_j[i];
				if (next_i >= 0 && next_j >= 0 && next_i < r && next_j < c){
					if (st[next_i][next_j] == '.'){	// ����ִ°� ��ä��
						st[next_i][next_j] = '*';
					}
				}
			}
		}

		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (check[i][j] == time){
					g.push({ i, j });
				}
			}
		}

		while (!g.empty()){
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
							check[next_i][next_j] = time + 1;
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