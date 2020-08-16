#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n, x, y, d, g;
int st[101][101];
int move_i[4] = { 1, 0, -1, 0 };
int move_j[4] = { 0, -1, 0, 1 };
vector<int> spin[20];
vector<int> cp[20];
queue<pair<int, int>> q;
int answer;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x >> y >> d >> g;
		//ó��
		spin[i].push_back(d);
		st[x][y] = 1;
		int current_i = x;
		int current_j = y;
		for (int j = 0; j <= g; j++){	// ���� 
			int g_idx = 1;
			if (j == 0){
				g_idx = 0;
			}
			if (j == 1){
				g_idx = 1;
			}
			if (j >= 2){
				g_idx = g_idx << (j-1);	// ���뺰 index ���
			}
			while (!cp[i].empty()){
				cp[i].pop_back();
			}
			for (int k = g_idx; k < spin[i].size(); k++){
				cp[i].push_back(spin[i][k]);
			}
			for (auto n_d : cp[i]){	// g��ŭ spin �߰��ؾ��Ѵ�
				int next_i = current_i + move_i[n_d];	// ���� ��ǥ ����
				int next_j = current_j + move_j[n_d];
				if (next_i >= 0 && next_j >= 0 && next_i <= 100 && next_j <= 100){
					st[next_i][next_j] = 1;	// ���� ���̸� üũ
					current_i = next_i;
					current_j = next_j;
				}
			}
			for (int k = 0; k < cp[i].size(); k++){
				cp[i].pop_back();
			}
			int v_size = spin[i].size();	// ���� ���� ������ ����
			for (int k = v_size-1; k >=0; k--){	// �������� �ؾ���
				int tmp = (spin[i][k] + 1)%4;
				spin[i].push_back(tmp);
			}
		}
	}

	for (int i = 0; i < 100; i++){	// 99���� ���������� +1 �� ����
		for (int j = 0; j < 100; j++){
			// ���簢�� ��� �� 1�ΰ�� ã��
			int x = i; int y = j;
			if (st[x][y] && st[x + 1][y] && st[x][y + 1] && st[x + 1][y + 1]){
				answer++;
			}
		}
	}

	cout << answer << endl;
}