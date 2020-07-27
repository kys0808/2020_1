#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, m;
vector<string> maze;
int check[101][101];
int move_i[4] = { 0, 0, 1, -1 };
int move_j[4] = { 1, -1, 0, 0 };
void solution(vector<string> maze){
	queue<pair<int, int>> tmp;
	tmp.push(make_pair(0, 0));
	check[0][0] = 1;
	while (!tmp.empty()){
		int p_i = tmp.front().first;
		int p_j = tmp.front().second;
		tmp.pop();
		int next_i;
		int next_j;
		for (int i = 0; i < 4; i++){
			next_i = p_i + move_i[i];
			next_j = p_j + move_j[i];
			if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < m){
				if (maze[next_i][next_j] == '1' && !check[next_i][next_j]){
					tmp.push(make_pair(next_i, next_j));
					check[next_i][next_j] = check[p_i][p_j] + 1;
				}
			}
		}
	}
}
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		maze.push_back(tmp);
	}
	solution(maze);
	cout << check[n - 1][m - 1];
}