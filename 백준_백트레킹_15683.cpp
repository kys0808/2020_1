#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int arr[9][9];
vector<pair<int, int>> cv;

int move_i[4] = {-1,0,1,0};
int move_j[4] = {0,1,0,-1};

int dir[9];	// cctv마다의 dir을 저장
int answer = 9999;
int cp[9][9];


void bfs(int c_i, int c_j, int dir){
	if (dir >= 4) dir = dir % 4;
	queue<pair<int, int>> q;
	q.push({ c_i, c_j });
	while (!q.empty()){
		int current_i = q.front().first;
		int current_j = q.front().second;
		q.pop();
		int next_i = current_i + move_i[dir];
		int next_j = current_j + move_j[dir];
		if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < m){
			if (cp[next_i][next_j] == 6){
				return;
			}
			if (cp[next_i][next_j] == 0 || cp[next_i][next_j] == 9){
				cp[next_i][next_j] = 9;
				q.push({ next_i, next_j });
			}
			if (cp[next_i][next_j]>0 && cp[next_i][next_j] <6){
				q.push({ next_i, next_j });
			}
		}
	}


}
void scan(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cp[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < cv.size(); i++){
		int current_i = cv[i].first;
		int current_j = cv[i].second;
		int cv_num = arr[current_i][current_j];
		if (cv_num == 1){
			bfs(current_i,current_j, dir[i]);
		}
		if (cv_num == 2){
			bfs(current_i, current_j, dir[i]);
			bfs(current_i, current_j, dir[i] + 2);
		}
		if (cv_num == 3){
			bfs(current_i, current_j, dir[i]);
			bfs(current_i, current_j, dir[i] + 1);
		}
		if (cv_num == 4){
			bfs(current_i, current_j, dir[i]);
			bfs(current_i, current_j, dir[i] + 1);
			bfs(current_i, current_j, dir[i] + 3);
		}
		if (cv_num == 5){
			bfs(current_i, current_j, dir[i]);
			bfs(current_i, current_j, dir[i] + 1);
			bfs(current_i, current_j, dir[i] + 2);
			bfs(current_i, current_j, dir[i] + 3);
		}
	}
}

void solve(){
	int tmp = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (cp[i][j] == 0){
				tmp++;
			}
		}
	}
	answer = min(answer, tmp);
}

void back(int depth){
	if (depth == cv.size()){
		scan();
		solve();
		return;
	}
	for (int i = 0; i < 4; i++){
		back(depth+1);
		dir[depth] = i;
	}
}


int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
			if (arr[i][j] > 0 && arr[i][j] < 6){
				cv.push_back({ i, j });
			}
		}
	}
	back(0);
	cout << answer;
}