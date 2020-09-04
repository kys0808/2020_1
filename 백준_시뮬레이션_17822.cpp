#include <iostream>
#include <vector>

using namespace std;

int n, m, t;
int x, d, k;	//  x���, d ����, k ĭ
vector<vector<int>> r;	// r�� ����


void spin(){
	for (int i = 0; i < n; i++){
		int num = i + 1;
		if (num % x == 0){	// ����� ȸ�� ����
			vector<int> tmp = r[i];
			if (d == 0){	// �ð�
				for (int j = 0; j < m; j++){
					r[i][j] = tmp[(j + (m - k)) % m];
				}
			}
			if (d == 1){	// �ݽð�
				for (int j = 0; j < m; j++){
					r[i][j] = tmp[(j + k) % m];
				}
			}
		}
	}
	/*
	cout << "ȸ����" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
	*/

	bool near = false;
	// ȸ�� �� ����ó�� ����
	vector<vector<int>> tmp_r = r;
	for (int i = 0; i < n; i++){
		for (int j = 1; j <= m - 2; j++){ // ������ ���� (�ι�° ������ ������ ��)
			int ch = tmp_r[i][j];
			if (ch != 0 && tmp_r[i][j - 1] != 0){
				if (ch == tmp_r[i][j - 1]){
					r[i][j - 1] = 0;
					r[i][j] = 0;
					near = true;
				}
			}
			if (ch != 0 && tmp_r[i][j + 1] != 0){
				if (ch == tmp_r[i][j + 1]){
					r[i][j + 1] = 0;
					r[i][j] = 0;
					near = true;
				}
			}
		}
		/*
		cout << "�߰� ó�� " << endl;
		for (int a = 0; a < n; a++){
			for (int b = 0; b < m; b++){
				cout << r[a][b] << " ";
			}
			cout << endl;
		}
		*/
		// ������ ó��
		if (tmp_r[i][0] == tmp_r[i][1]){
			if (tmp_r[i][0] != 0 && tmp_r[i][1] != 0){
				r[i][0] = 0;
				r[i][1] = 0;
				near = true;
			}
		}
		if (tmp_r[i][m - 1] == tmp_r[i][m - 2]){
			if (tmp_r[i][m - 1] != 0 && tmp_r[i][m - 2] != 0){
				r[i][m - 1] = 0;
				r[i][m - 2] = 0;
				near = true;
			}
		}
		if (tmp_r[i][m - 1] == tmp_r[i][0]){
			if (tmp_r[i][m - 1] != 0 && tmp_r[i][0] != 0){
				r[i][m - 1] = 0;
				r[i][0] = 0;
				near = true;
			}
		}
	}
	/*
	cout << "��������ó�� ��" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
	*/
	// ���α��� ����

	for (int j = 0; j < m; j++){
		for (int i = 1; i <= n-2; i++){
			int ch = tmp_r[i][j];
			if (ch != 0 && tmp_r[i - 1][j] != 0){
				if (ch == tmp_r[i - 1][j]){
					r[i - 1][j] = 0;
					r[i][j] = 0;
					near = true;
				}
			}
			if (ch != 0 && tmp_r[i + 1][j] != 0){
				if (ch == tmp_r[i + 1][j]){
					r[i + 1][j] = 0;
					r[i][j] = 0;
					near = true;
				}
			}
		}
		if (tmp_r[0][j] == tmp_r[1][j]){
			if (tmp_r[0][j] != 0 && tmp_r[1][j] != 0){
				r[0][j] = 0;
				r[1][j] = 0;
				near = true;
			}
		}
		if (tmp_r[n - 1][j] == tmp_r[n - 2][j]){
			if (tmp_r[n - 1][j] != 0 && tmp_r[n - 2][j] != 0){
				r[n - 1][j] = 0;
				r[n - 2][j] = 0;
				near = true;
			}
		}
	}
	/*
	cout << "����ó�� ��" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
	*/
	if (near == false){	// ��� ���� +1, -1 ó��
		float mid = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (r[i][j] != 0){
					mid += r[i][j];
					cnt++;
				}
			}
		}
		mid = (mid / cnt);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (r[i][j]){
					if (r[i][j] > mid){
						r[i][j] -= 1;
					}
					else if (r[i][j] < mid){
						r[i][j] += 1;
					}
				}
			}
		}
		/*
		cout << "���ó�� ��" << endl;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cout << r[i][j] << " ";
			}
			cout << endl;
		}
		*/
	}
}

int main(){
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++){	// n�� ���� m�� ��
		vector<int> tmp;
		for (int j = 0; j < m; j++){	// m�� ��
			int num;
			cin >> num;
			tmp.push_back(num);
		}
		r.push_back(tmp);
	}
	for (int i = 0; i < t; i++){
		cin >> x >> d >> k;
		spin();
	}
	int answer = 0;
	for (int i = 0; i < r.size(); i++){
		for (int j = 0; j < m; j++){
			answer += r[i][j];
		}
	}
	cout << answer << endl;
}