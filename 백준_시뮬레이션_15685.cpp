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
		//처리
		spin[i].push_back(d);
		st[x][y] = 1;
		int current_i = x;
		int current_j = y;
		for (int j = 0; j <= g; j++){	// 세대 
			int g_idx = 1;
			if (j == 0){
				g_idx = 0;
			}
			if (j == 1){
				g_idx = 1;
			}
			if (j >= 2){
				g_idx = g_idx << (j-1);	// 세대별 index 계산
			}
			while (!cp[i].empty()){
				cp[i].pop_back();
			}
			for (int k = g_idx; k < spin[i].size(); k++){
				cp[i].push_back(spin[i][k]);
			}
			for (auto n_d : cp[i]){	// g만큼 spin 추가해야한다
				int next_i = current_i + move_i[n_d];	// 다음 좌표 설정
				int next_j = current_j + move_j[n_d];
				if (next_i >= 0 && next_j >= 0 && next_i <= 100 && next_j <= 100){
					st[next_i][next_j] = 1;	// 범위 안이면 체크
					current_i = next_i;
					current_j = next_j;
				}
			}
			for (int k = 0; k < cp[i].size(); k++){
				cp[i].pop_back();
			}
			int v_size = spin[i].size();	// 현재 상태 사이즈 저장
			for (int k = v_size-1; k >=0; k--){	// 역순으로 해야함
				int tmp = (spin[i][k] + 1)%4;
				spin[i].push_back(tmp);
			}
		}
	}

	for (int i = 0; i < 100; i++){	// 99까지 보는이유는 +1 비교 때문
		for (int j = 0; j < 100; j++){
			// 정사각형 모두 다 1인경우 찾기
			int x = i; int y = j;
			if (st[x][y] && st[x + 1][y] && st[x][y + 1] && st[x + 1][y + 1]){
				answer++;
			}
		}
	}

	cout << answer << endl;
}