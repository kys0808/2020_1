#include <iostream>

using namespace std;


int n;
int status[21][21];
bool check[21];
int answer=10000000;

void dfs(int player_num, int cnt){
	if (cnt == n / 2){
		int start = 0;
		int link = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (check[i] && check[j]){
					start += status[i][j];
				}
				if (!check[i] && !check[j]){
					link += status[i][j];
				}
			}
		}
		int tmp;
		tmp = start - link;
		if (tmp < 0)
			tmp = -tmp;
		if (answer > tmp)
			answer = tmp;
		return;
	}
	for (int i = player_num; i < n; i++){
		check[i] = true;
		dfs(i+ 1, cnt + 1);
		check[i] = false;
	}
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> status[i][j];
		}
	}
	dfs(1, 0);
	cout << answer;
}