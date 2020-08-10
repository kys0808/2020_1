#include <iostream>
#include <algorithm>
using namespace std;

int n, m, h;	// n���� ���μ� // h���� ���μ� //m�� ���μ� ����
int arr[31][11];	// [���μ�][���μ�] // h,n
int answer = 99999;

bool check_result(){
	bool check = true;
	for (int i = 1; i <= n; i++){	// ���� ��߼�
		int status = i;
		//cout << status << endl;
		for (int j = 1; j <= h; j++){	// �ϳ��ϳ� ��������
			if (arr[j][status]){
				status = arr[j][status];	// ��ٸ� ������ Ÿ��
				//cout << status << endl;
			}
		}
		if (status != i){
			check = false;
			return check;
		}
	}
	return check;
}

void dfs(int cnt,int start_i){
	bool check = true;
	check = check_result();
	if (cnt == 3){
		if (check == true){
			answer = min(answer, cnt);
			// cnt == 3�Ǹ� ã�Ҵ��� ��ã�Ҵ��� üũ�ϰ� return �ؾ���
			return;
		}
		return;
	}
	if (check == true){
		answer = min(answer, cnt);
		return;
	}
	for (int i = start_i; i <= h; i++){	// h�� ���� n�� ����
		for (int j = 1; j <= n - 1; j++){	// ����
			if (!arr[i][j] && !arr[i][j + 1]){	// ���ڸ��� ��ٸ��� ����߉�
				arr[i][j] = j + 1;
				arr[i][j + 1] = j;
				dfs(cnt + 1, i);
				arr[i][j + 1] = 0;
				arr[i][j] = 0;
			}
		}
	}
}

int main(){
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		arr[a][b] = b+1;	// ����b������ �����ϸ� b+1��
		arr[a][b + 1] = b;	// ���� b+1�� �����ϸ� b��
	}
	dfs(0,1);
	if (answer > 3){
		answer = -1;
	}
	cout << answer;
}