#include <iostream>
#include <vector>

using namespace std;

int arr[21][21];	// �ٴڸ�

int dice[6];

int n, m, x, y, k;
vector<int> mv;


void spin(int dir){	// dir 1 �� / 2 �� / 3 �� / 4 ��
	if (dir == 1){	// ��
		int tdice[6];
		for (int i = 0; i < 6; i++)
			tdice[i] = dice[i];
		dice[0] = tdice[3];
		dice[3] = tdice[5];
		dice[5] = tdice[2];
		dice[2] = tdice[0];
	}
	if (dir == 2){	// ��
		int tdice[6];
		for (int i = 0; i < 6; i++)
			tdice[i] = dice[i];
		dice[0] = tdice[2];
		dice[2] = tdice[5];
		dice[5] = tdice[3];
		dice[3] = tdice[0];
	}
	if (dir == 3){	// ��
		int tdice[6];
		for (int i = 0; i < 6; i++)
			tdice[i] = dice[i];
		dice[0] = tdice[4];
		dice[4] = tdice[5];
		dice[5] = tdice[1];
		dice[1] = tdice[0];

	}
	if (dir == 4){	// ��
		int tdice[6];
		for (int i = 0; i < 6; i++)
			tdice[i] = dice[i];
		dice[0] = tdice[1];
		dice[1] = tdice[5];
		dice[5] = tdice[4];
		dice[4] = tdice[0];
	}
}

void change(int current_i, int current_j){
	if (arr[current_i][current_j] == 0){	//�ٴ� �� ���ڰ� 0�̸�
		arr[current_i][current_j] = dice[5];
	}
	else if (arr[current_i][current_j] != 0){
		dice[5] = arr[current_i][current_j];
		arr[current_i][current_j] = 0;
	}
}
int main(){
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < k; i++){
		int tmp;
		cin >> tmp;
		mv.push_back(tmp);
	}
	change(x, y);
	int current_i = x;	// ��
	int current_j = y;	// ��	
	for (int i = 0; i < mv.size(); i++){
		int dir = mv[i];
		// �ٴڹ�ȣ�� ���� arr�� �� �� ����
		if (dir == 1){	// ��
			if (current_j+1 <m){
				current_j += 1;
				spin(dir);
				change(current_i, current_j);
				cout << dice[0] << endl;
			}
		}
		if (dir == 2){	// ��
			if (current_j -1 >=0){
				current_j -= 1;
				spin(dir);
				change(current_i, current_j);
				cout << dice[0] << endl;
			}
		}
		if (dir == 3){	// ��
			if (current_i -1 >=0){
				current_i -= 1;
				spin(dir);
				change(current_i, current_j);
				cout << dice[0] << endl;
			}
		}
		if (dir == 4){	// ��
			if (current_i +1 <n){
				current_i += 1;
				spin(dir);
				change(current_i, current_j);
				cout << dice[0] << endl;
			}
		}
	}
}