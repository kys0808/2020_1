#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[21][21];
vector<int> dir, tt;

int cp[21][21];		// 방향 완성되면 카피떠서 방향만큼 진행
int answer;

void solve(){
	for (int i = 0; i < n; i++){	// 일단 복사 뜨고
		for (int j = 0; j < n; j++){
			cp[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < dir.size(); i++){
		vector<int> tmp;
		if (dir[i] == 0){	// 상
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					if (cp[k][j]){	// 값이 있으면 tmp 에 넣기
						tmp.push_back(cp[k][j]);
						cp[k][j] = 0;
					}
				}
				int idx = 0;
				if (!tmp.empty()){
					for (int k = 0; k < tmp.size(); k++){
						if (k+1<tmp.size()&&tmp[k] == tmp[k + 1]){
							cp[idx][j] = tmp[k] * 2;
							idx++;
							k++;
						}
						else{
							cp[idx][j] = tmp[k];
							idx++;
						}
					}
				}
				tmp.clear();
			}
		}
		if (dir[i] == 1){	// 우
			for (int j = 0; j < n; j++){
				for (int k = n - 1; k >= 0; k--){
					if (cp[j][k]){	// 값이 있으면 tmp 에 넣기
						tmp.push_back(cp[j][k]);
						cp[j][k] = 0;
					}
				}
				int idx = 0;
				if (!tmp.empty()){
					for (int k = 0; k < tmp.size(); k++){
						if (k+1<tmp.size() && tmp[k] == tmp[k + 1]){
							cp[j][n - idx - 1] = tmp[k] * 2;
							idx++;
							k++;
						}
						else{
							cp[j][n - idx - 1] = tmp[k];
							idx++;
						}
					}
				}
				tmp.clear();
			}
		}
		if (dir[i] == 2){	// 하
			for (int j = 0; j < n; j++){
				for (int k = n - 1; k >= 0; k--){
					if (cp[k][j]){	// 값이 있으면 tmp 에 넣기
						tmp.push_back(cp[k][j]);
						cp[k][j] = 0;
					}
				}
				// 한줄 다 넣었으면 tmp에서 위에서부터 값 뽑아내자 -- 땡기기
				int idx = 0;
				if (!tmp.empty()){
					for (int k = 0; k < tmp.size(); k++){
						if (k+1<tmp.size() && tmp[k] == tmp[k + 1]){
							cp[n - idx - 1][j] = tmp[k] * 2;
							idx++;
							k++;
						}
						else{
							cp[n - idx - 1][j] = tmp[k];
							idx++;
						}
					}
				}
				tmp.clear();
			}
		}
		if (dir[i] == 3){	// 좌
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					if (cp[j][k]){	// 값이 있으면 tmp 에 넣기
						tmp.push_back(cp[j][k]);
						cp[j][k] = 0;
					}
				}
				// 한줄 다 넣었으면 tmp에서 위에서부터 값 뽑아내자 -- 땡기기
				int idx = 0;
				if (!tmp.empty()){
					for (int k = 0; k < tmp.size(); k++){
						if (k+1<tmp.size() && tmp[k] == tmp[k + 1]){
							cp[j][idx++] = tmp[k] * 2;
							k++;
						}
						else{
							cp[j][idx++] = tmp[k];
						}
					}
				}
				tmp.clear();
			}
		}
	}
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			if (cp[j][k]){
				answer = max(answer, cp[j][k]);
			}
		}
	}
}

void back(int depth){
	if (depth == 5){
		solve();
		return;
	}
	for (int i = 0; i < 4; i++){
		dir.push_back(i);	// 0,1,2,3 == 상 우 좌 하
		back(depth+1);
		dir.pop_back();
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	back(0);
	cout << answer << endl;
}