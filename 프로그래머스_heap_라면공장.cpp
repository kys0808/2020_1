#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int day = 0;
	priority_queue<pair<int, int>> pq;
	priority_queue<pair<int, int>> pq2;
	for (int i = 0; i < dates.size(); i++){
		pq.push(make_pair(supplies[i], dates[i]));
	}
	pq2 = pq;
	int sum = stock;
	int a = stock;
	while (1){
		pq = pq2;
		if (pq.top().second <= day)
			pq.pop();
		if (a - pq.top().second + day < 0){
			//공급 못받음
			pq.pop();
		}
		cout << "day " << day << "sum " << sum << "stock " << a << endl;

		else{
			answer++;
			day = pq.top().second;
			a = a - (pq.top().second - day) + pq.top().first;
			sum += pq.top().first;
			if (sum >= k)
				break;
		}
	}

	cout << answer;
	return answer;
}