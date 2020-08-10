#include <iostream>
#include <algorithm>
using namespace std;

int n, m, h;	// n개의 세로선 // h개의 가로선 //m개 가로선 놓자
int arr[31][11];	// [가로선][세로선] // h,n
int answer = 99999;

bool check_result(){
	bool check = true;
	for (int i = 1; i <= n; i++){	// 세로 출발순
		int status = i;
		//cout << status << endl;
		for (int j = 1; j <= h; j++){	// 하나하나 내려간다
			if (arr[j][status]){
				status = arr[j][status];	// 사다리 있으면 타고가
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
			// cnt == 3되면 찾았는지 못찾았는지 체크하고 return 해야지
			return;
		}
		return;
	}
	if (check == true){
		answer = min(answer, cnt);
		return;
	}
	for (int i = start_i; i <= h; i++){	// h가 가로 n이 세로
		for (int j = 1; j <= n - 1; j++){	// 세로
			if (!arr[i][j] && !arr[i][j + 1]){	// 그자리에 사다리가 없어야됑
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
		arr[a][b] = b+1;	// 세로b번으로 접근하면 b+1로
		arr[a][b + 1] = b;	// 세로 b+1로 접근하면 b로
	}
	dfs(0,1);
	if (answer > 3){
		answer = -1;
	}
	cout << answer;
}