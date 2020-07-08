#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>	// priority_queue 오름차순(greater)를 위해서
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue < int, vector<int>, greater<int> > q;
	for (int i = 0; i < scoville.size(); i++){
		q.push(scoville[i]);
	}
	while (1){
		int a = 0;
		if (q.top() < K){
			a = q.top();
			q.pop();
			a += q.top() * 2;
			q.pop();
			q.push(a);
			answer++;
		}
		else{
			break;
		}
	}
	cout << answer;
	return answer;
}