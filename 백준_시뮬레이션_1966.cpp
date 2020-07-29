#include <iostream>
#include <queue>

using namespace std;


int main(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;
			q.push(make_pair(tmp, i));
			pq.push(tmp);
		}
		int answer = 0;
		while (!pq.empty()){
			int prime = q.front().first;
			int index = q.front().second;
			if (prime == pq.top()){
				answer++;
				pq.pop();
				q.pop();
				if (index == m){
					break;
				}
			}
			else{
				q.push(make_pair(prime, index));
				q.pop();
			}
		}
		cout << answer << endl;
	}
}