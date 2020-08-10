#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

// deque -- front 와 back 을 push , pop 가능
// vector처럼 index로 참조가 가능하다
int n, k,l;
int arr[101][101];

int move_i[4] = { 0, 1, 0,  -1};
int move_j[4] = { 1, 0, -1,  0};
int answer = 0;
vector<pair<int, char>> shift_dir;
deque<pair<int, int>> position;

void dfs(int start_i, int start_j, int second, int dir,int length){
	for (int i = 0; i < shift_dir.size(); i++){
		if (shift_dir[i].first == second){
			if (shift_dir[i].second == 'L'){
				dir = (dir + 3) % 4;
			}
			if (shift_dir[i].second == 'D'){
				dir = (dir + 1) % 4;
			}
		}
	}
	int next_i = start_i + move_i[dir];
	int next_j = start_j + move_j[dir];
	if (next_i <1 || next_j <1 || next_i >n || next_j >n){
		answer = second;
		return;
	}
	for (int i = 0; i < position.size(); i++){
		if (position[i].first == next_i && position[i].second == next_j){
			answer = second;
			return;
		}
	}
	if (arr[next_i][next_j] == 2){
		position.push_front({ next_i, next_j });
		arr[next_i][next_j] = 0;
		dfs(next_i,next_j,second+1,dir,length+1);
		arr[next_i][next_j] = 2;
	}
	if (arr[next_i][next_j] != 2){
		position.push_front({ next_i, next_j });
		position.pop_back();
		dfs(next_i,next_j,second+1,dir,length);
	}
}

int main(){
	cin >> n >> k;
	for (int i = 0; i < k; i++){
		int tmp_i, tmp_j;
		cin >> tmp_i >> tmp_j;
		arr[tmp_i][tmp_j] = 2;	// 2는 사과
	}
	cin >> l;
	for (int i = 0; i < l; i++){
		int tmp; char c;	// L은 왼쪽으로 90도, D는 오른쪽으로 90도
		cin >> tmp >> c;
		shift_dir.push_back(make_pair(tmp,c));	
	}
	position.push_front({ 1, 1 });
	dfs(1,1,0,0,1);
	cout << answer+1 << endl;
}