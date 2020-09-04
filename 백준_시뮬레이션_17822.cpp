#include <iostream>
#include <vector>

using namespace std;

int n, m, t;
int x, d, k;	//  x배수, d 방향, k 칸
vector<vector<int>> r;	// r은 원판


void spin(){
	for (int i = 0; i < n; i++){
		int num = i + 1;
		if (num % x == 0){	// 배수면 회전 진행
			vector<int> tmp = r[i];
			if (d == 0){	// 시계
				for (int j = 0; j < m; j++){
					r[i][j] = tmp[(j + (m - k)) % m];
				}
			}
			if (d == 1){	// 반시계
				for (int j = 0; j < m; j++){
					r[i][j] = tmp[(j + k) % m];
				}
			}
		}
	}
	/*
	cout << "회전끝" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
	*/

	bool near = false;
	// 회전 끝 숫자처리 시작
	vector<vector<int>> tmp_r = r;
	for (int i = 0; i < n; i++){
		for (int j = 1; j <= m - 2; j++){ // 가생이 빼고 (두번째 수부터 마지막 전)
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
		cout << "중간 처리 " << endl;
		for (int a = 0; a < n; a++){
			for (int b = 0; b < m; b++){
				cout << r[a][b] << " ";
			}
			cout << endl;
		}
		*/
		// 가생이 처리
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
	cout << "가로인접처리 끝" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
	*/
	// 세로기준 시작

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
	cout << "인접처리 끝" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
	*/
	if (near == false){	// 평균 세고 +1, -1 처리
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
		cout << "평균처리 끝" << endl;
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
	for (int i = 0; i < n; i++){	// n개 원판 m개 수
		vector<int> tmp;
		for (int j = 0; j < m; j++){	// m개 수
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