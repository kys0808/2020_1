#include <iostream>
#include <algorithm>
using namespace std;

int dist[101][101];

int n,m;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dist[i][j] = 99999999;
		}
	}
	for (int i = 0; i < m; i++){
		int s, e, d;
		cin >> s >> e >> d;
		dist[s][e] = min(dist[s][e],d);
	}

	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (dist[i][k] != 99999999 && dist[k][j] != 99999999)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (dist[i][j] == 99999999 || i == j)
				dist[i][j] = 0;
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}