#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

/*
bfs Ǯ��
1. start index ���� check �湮
2. while(!q.empty())
3. q�� top index Ȯ�� �� pop()
4. new index�� ���� check Ȯ�� �� push()
5. 2-4 �ݺ�

==> �ִܰŸ� ���ϴ� ���������� bfs�� �����ϴ�!!
*/


int check[51][51];
vector<string> v;
int max_num = 0;
int a;
int b;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
void bfs(int start_i, int start_j){
	queue<pair<int,int>> q;
	q.push(make_pair(start_i, start_j));
	check[start_i][start_j] =1;
	while (!q.empty()){
		int p_i = q.front().first;
		int p_j = q.front().second;
		q.pop();// �ش� �湮
		for (int i = 0; i < 4; i++){
			int next_i = p_i + dx[i];
			int next_j = p_j + dy[i];
			if (next_i >= 0 && next_j >= 0 && next_i < a&&next_j<b){
				if (!check[next_i][next_j] && v[next_i][next_j] == 'L'){
					check[next_i][next_j] = check[p_i][p_j] + 1;
					if (max_num<check[next_i][next_j])
						max_num = check[next_i][next_j];
					q.push(make_pair(next_i, next_j));
				}
			}
		}
	}
}
int main(){
	cin >> a >> b;
	for (int i = 0; i < a; i++){
		string tmp;
		cin >> tmp;
		v.push_back(tmp); // tmp[i][j] ���� i�� �� j�� ��
	}
	int time = 0;
	for (int i = 0; i < a; i++){
		for (int j = 0; j < b; j++){
			memset(check, 0, sizeof(check));
			if (v[i][j] == 'L'){	// ���������� bfs
				bfs(i, j);
			}
		}
	}
	cout << max_num << endl;
}


