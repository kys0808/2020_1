#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;


int n, m;
vector < pair<int, int> >graph[20001];
int dist[20001];
// ���ͽ�Ʈ�� (pq�̿�)
// O(E*logN)	E :���� N: ����

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int start;
	//cin >> n >> m;
	//cin >> start;
	scanf("%d %d", &n, &m);
	scanf("%d", &start);

	//1) �׷��� ��� ����� ��� �Է�
	for (int i = 0; i < m; i++){
		int u, v, w;
		//cin >> u >> v >> w;
		scanf("%d %d %d", &u, &v, &w);
		// u-> v�� ���µ� ��� w
		graph[u].push_back({ w, v });
	}
	//2) node ��ȣ�� ��� �ʱ�ȭ
	for (int i = 1; i <= n; i++){
		dist[i] = 99999999;
	}

	//3) pq ��� <-cost, node_num> ��
	//	-cost�� �Է��ϴ� ������ pq�� ������������ �����ϴ°��� �⺻�̴�. ���� ����� �������� ���� ������� �����ϱ� ����
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });	// ������, ����� 0
	dist[start] = 0;		// �������� ����� 0

	while (!pq.empty()){
		int current = pq.top().second;
		int cost = -1*pq.top().first;	// ��� �����̱� ������ -1ó��
		pq.pop();
		for (int i = 0; i < graph[current].size(); i++){
			int next = graph[current][i].second;
			int ncost = graph[current][i].first;
			if (dist[next] > cost + ncost){	// ������ ��뺸�� �� ���� ����� �����ϸ� ���� �� pq�Է�
				dist[next] = cost + ncost;
				pq.push({ -1 * dist[next], next });
			}
		}
	}

	for (int i = 1; i <= n; i++){
		if (dist[i] == 99999999){
			printf("INF\n");
		}
		else{
			printf("%d\n", dist[i]);
		}
	}


}