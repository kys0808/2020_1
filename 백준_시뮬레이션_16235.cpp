#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int n, m, k; int x, y, z;
int st[11][11];	// ���
vector<int> tree[11][11];
vector<int> die_tree[11][11];

int arr[11][11];	// �ܿﶧ �߰� ���
int move_i[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int move_j[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };


void tree_sort(){
	for (int i = 1; i <= n; i++){	// sort �ѹ� �ϰ�
		for (int j = 1; j <= n; j++){
			if (!tree[i][j].empty()){
				sort(tree[i][j].begin(), tree[i][j].end());
			}
		}
	}
}

void spring(){
	tree_sort();
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 0; k < tree[i][j].size(); k++){
				if (!tree[i][j].empty()){
					if (st[i][j] >= tree[i][j][k]){
						st[i][j] -= tree[i][j][k];	// ������ ���ְ�
						tree[i][j][k] += 1;	// ���� �Ծ���
					}
					else{ // ���� ����ó��
						die_tree[i][j].push_back(tree[i][j][k]);
						tree[i][j][k] = 99999;	// 9999�� ��������
					}
				}
			}
		}
	}
	// ���� ���� pop
	tree_sort();
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			while (!tree[i][j].empty()){
				if (tree[i][j].back() == 99999){
					tree[i][j].pop_back();
				}
				else{
					break;
				}
			}
		}
	}
}

void summer(){	// ���� ���� ������ ������� �ȴ�.
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 0; k < die_tree[i][j].size(); k++){
				if (!die_tree[i][j].empty()){
					st[i][j] += (die_tree[i][j][k] / 2);
				}
			}
			die_tree[i][j].clear();
		}
	}
}

void fall(){	// 5��� ���� �ؾ���
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 0; k < tree[i][j].size(); k++){
				if (!tree[i][j].empty()){
					if (tree[i][j][k] % 5 == 0){
						int c_i = i;
						int c_j = j;
						for (int k = 0; k < 8; k++){
							int next_i = c_i + move_i[k];
							int next_j = c_j + move_j[k];
							if (next_i >= 1 && next_j >= 1 && next_i <= n && next_j <= n){
								tree[next_i][next_j].push_back(1);
							}
						}
					}
				}
			}
		}
	}
}

void winter(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			st[i][j] += arr[i][j];
		}
	}
}


int main(){
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> arr[i][j];
			st[i][j] = 5;	// �ʱ� ��� ����
		}
	}
	for (int i = 0; i < m; i++){
		cin >> x >> y >> z;	// x,y�� ������ġ z�� ��������
		tree[x][y].push_back(z);
	}
	for (int i = 1; i <= k; i++){
		spring();
		summer();
		fall();
		winter();
	}

	int answer = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			answer += tree[i][j].size();
		}
	}
	cout << answer << endl;
}