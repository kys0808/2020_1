#include <iostream>
#include <vector>
#include <cstring>
using namespace std;



int r, c, t;
int st[51][51];
int cp[51][51];
int move_i[4] = { 0, 0, 1, -1 };
int move_j[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> filter;

void spread(){
	for (int i = 0; i < r; i++){	// ���� copy
		for (int j = 0; j < c; j++){
			cp[i][j] = st[i][j];
		}
	}

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){	// Ȯ��
			if (cp[i][j] >0){	// �̼����� �����ϸ�
				vector<pair<int, int>> tmp;
				for (int k = 0; k < 4; k++){
					int next_i = i + move_i[k];
					int next_j = j + move_j[k];
					if (next_i >= 0 && next_j >= 0 && next_i < r && next_j < c ){
						if (!((next_i == filter[0].first && next_j == filter[0].second) || (next_i == filter[1].first && next_j == filter[1].second))){
							// 4���⿡�� ������ ���� üũ
							tmp.push_back({ next_i, next_j });
						}
					}
				}
				int cnt = tmp.size();	// size��ŭ ���� �̼����� ���
				int plus = cp[i][j] / 5;
				for (int k = 0; k < tmp.size(); k++){
					int c_i = tmp[k].first;
					int c_j = tmp[k].second;
					st[c_i][c_j] += plus;
				}
				st[i][j] -= plus*cnt;
				tmp.clear();
			}
		}
	}

}
void acting(){	// �о��
	// 1��° ����û����
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cp[i][j] = st[i][j];
		}
	}
	int c_i = filter[0].first;
	int c_j = filter[0].second;
	st[c_i][c_j] = 0;
	// ��
	for (int j = c_j + 1; j < c; j++){
		st[c_i][j] = cp[c_i][j - 1];
	}
	//��
	for (int i = c_i - 1; i >= 0; i--){
		st[i][c - 1] = cp[i + 1][c - 1];
	}
	// ��
	for (int j = c - 1 - 1; j >= 0; j--){
		st[0][j] = cp[0][j + 1];
	}
	// ��
	for (int i = 1; i <= c_i; i++){
		st[i][0] = cp[i - 1][0];
	}
	// 2��° ����û����
	c_i = filter[1].first;
	c_j = filter[1].second;
	// ��
	for (int j = c_j + 1; j < c; j++){
		st[c_i][j] = cp[c_i][j - 1];
	}
	// ��
	for (int i = c_i + 1; i < r; i++){
		st[i][c - 1] = cp[i - 1][c - 1];
	}
	// ��
	for (int j = c - 1 - 1; j >= 0; j--){
		st[r - 1][j] = cp[r - 1][j + 1];
	}
	// ��
	for (int i = r - 1 - 1; i >= c_i; i--){
		st[i][0] = cp[i + 1][0];
	}
	// ������ ����û���� �ڸ� ó��
	st[filter[0].first][filter[0].second] = -1;
	st[filter[0].first][filter[0].second+1] = 0;
	st[filter[1].first][filter[1].second] = -1;
	st[filter[1].first][filter[1].second+1] = 0;
}


int main(){
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> st[i][j];
			if (st[i][j] == -1){
				filter.push_back({ i, j });
			}
		}
	}
	for (int i = 1; i <= t; i++){
		spread();
		/*
		cout << "Ȯ�� ��" << endl;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				cout << st[i][j] << " ";
			}
			cout << endl;
		}
		*/
		acting();
		/*
		cout << "������ ��" << endl;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				cout << st[i][j] << " ";
			}
			cout << endl;
		}
		*/
	}
	int answer = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (st[i][j] > 0)
				answer += st[i][j];
		}
	}
	cout << answer << endl;
}