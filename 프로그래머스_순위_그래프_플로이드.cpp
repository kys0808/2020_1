#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dist[101][101];
#define MAX_DIST 99999;

// �÷��̵� - �����<-> ����� ������ �ִܰ�θ� ���϶�
// Ư�� �߰� �������� �����ؼ� �ִܰ�θ� �����ϴ� ��� 
// 3�� for�� �̱⶧���� O(V^3)	// �������� 3��ø (k,i,j ==> min(dist[i][j], dist[i][k]+dist[k][j])

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	// 1) ���� ����ġ �ʱ�ȭ
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dist[i][j] = 0;
		}
	}
	// 2) ���� ����ġ �ο�
	for (int i = 0; i < results.size(); i++){
		int win = results[i][0];
		int lose = results[i][1];
		dist[win][lose] = 1;
	}

	// 3) �÷��̵� ����
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (dist[i][k] && dist[k][j]){
					dist[i][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++){
		int count = 0;
		for (int j = 1; j <= n; j++){
			if (dist[i][j] || dist[j][i]){	// ���� �ϳ��� �̰����� ���а� Ȯ���ϴ�
				count++;
			}
		}
		if (count == n - 1){
			answer++;
		}
	}
	cout << answer << endl;
	return answer;
}

int main(){
	int n = 5;
	vector<vector<int>> results = { { 4, 3 }, { 4, 2 }, { 3, 2 }, { 1, 2 }, { 2, 5 } };
	solution(n, results);
}