#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>


using namespace std;

int status[21][21];
pair<int, int> dest[401];

int n, m, gas;
int start_i;
int start_j;

int move_i[4] = { 0, 0, 1, -1 };
int move_j[4] = { 1, -1, 0, 0 };

struct customer{
	int i;
	int j;
	int num;
	int dist;
};

bool cmp(customer a, customer b){
	if (a.dist < b.dist){
		return true;
	}
	else if (a.dist == b.dist){
		if (a.i < b.i){
			return true;
		}
		else if (a.i == b.i){
			if (a.j < b.j){
				return true;
			}
			else return false;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

int main(){
	cin >> n >> m >> gas;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> status[i][j];
			if (status[i][j] == 1){
				status[i][j] = -1;
			}
		}
	}
	cin >> start_i >> start_j;
	for (int i = 1; i <= m; i++){
		int s_i, s_j, e_i, e_j;
		cin >> s_i >> s_j >> e_i >> e_j;
		status[s_i][s_j] = i;
		dest[i].first = e_i;
		dest[i].second = e_j;
	}

	int	end_count = 0;

	while (end_count < m){
		int first_check[21][21];
		int first_dist[21][21];
		memset(first_check, 0, sizeof(first_check));
		memset(first_dist, 0, sizeof(first_dist));
		// 손님 있는 곳으로 이동거리
		queue<pair<int, int>> first_q;
		first_q.push({ start_i, start_j });
		first_check[start_i][start_j] = 1;
		while (!first_q.empty()){
			int first_c_i = first_q.front().first;
			int first_c_j = first_q.front().second;
			first_q.pop();
			for (int k = 0; k < 4; k++){
				int first_n_i = first_c_i + move_i[k];
				int first_n_j = first_c_j + move_j[k];
				if (first_n_i >= 1 && first_n_j >= 1 && first_n_i <= n && first_n_j <= n){
					if (first_check[first_n_i][first_n_j] == 0){
						if (status[first_n_i][first_n_j] != -1){
							first_check[first_n_i][first_n_j] = 1;
							first_dist[first_n_i][first_n_j] = first_dist[first_c_i][first_c_j] + 1;
							first_q.push({ first_n_i, first_n_j });
						}
					}
				}
			}
		}

		vector<customer> v;
		v.clear();
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (status[i][j] >= 1 && first_check[i][j] == 1){
					customer c;
					c.i = i;
					c.j = j;
					c.dist = first_dist[i][j];
					c.num = status[i][j];
					v.push_back(c);
				}
			}
		}
		if (v.empty()){
			cout << -1;
			return 0;
		}
		sort(v.begin(), v.end(), cmp);
		if (gas - v[0].dist< 0){
			cout << -1;
			return 0;
		}
		else{
			gas -= v[0].dist;
			int sec_check[21][21];
			int sec_dist[21][21];
			memset(sec_check, 0, sizeof(sec_check));
			memset(sec_dist, 0, sizeof(sec_dist));
			queue<pair<int, int>> s_q;
			s_q.push({ v[0].i, v[0].j });
			sec_check[v[0].i][v[0].j] = 1;
			while (!s_q.empty()){
				int sec_c_i = s_q.front().first;
				int sec_c_j = s_q.front().second;
				s_q.pop();
				for (int k = 0; k < 4; k++){
					int sec_n_i = sec_c_i + move_i[k];
					int sec_n_j = sec_c_j + move_j[k];
					if (sec_n_i >= 1 && sec_n_j >= 1 && sec_n_i <= n && sec_n_j <= n){
						if (sec_check[sec_n_i][sec_n_j] == 0){
							if (status[sec_n_i][sec_n_j] != -1){
								sec_check[sec_n_i][sec_n_j] = 1;
								sec_dist[sec_n_i][sec_n_j] = sec_dist[sec_c_i][sec_c_j] + 1;
								s_q.push({ sec_n_i, sec_n_j });
							}
						}
					}
				}
			}
			if (status[dest[v[0].num].first][dest[v[0].num].second] == -1){
				cout << -1;
				return 0;
			}
			int using_gas = sec_dist[dest[v[0].num].first][dest[v[0].num].second];
			if (gas - using_gas < 0){
				cout << -1;
				return 0;
			}
			else{
				gas += using_gas;
				start_i = dest[v[0].num].first;
				start_j = dest[v[0].num].second;
				if (sec_check[start_i][start_j] == 1){
					status[v[0].i][v[0].j] = 0;
					end_count++;
				}
				else{
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << gas << endl;
}