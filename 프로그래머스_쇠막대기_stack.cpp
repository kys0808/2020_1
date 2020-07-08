#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int second = 0;
	int total_weight = 0;
	queue<int> q1;
	queue<pair<int, int>> q2;
	for (int i = 0; i < truck_weights.size(); i++){
		q1.push(truck_weights[i]);
	}
	while (1){
		//종료조건 뭐라해야하지
		second++;
		if (!q1.empty()){
			if (total_weight + q1.front() < weight){
				q2.push(make_pair(q1.front(), second));
				total_weight += q1.front();
				//cout << "push : "<<q1.front() << endl;
				q1.pop();
			}
		}
		if (!q2.empty()){
			if (q2.front().second == (second - bridge_length)){
				total_weight -= q2.front().first;
				//cout << "pop : "<<q2.front().first << endl;
				q2.pop();
			}
		}
		if (q1.empty() && q2.empty())
			break;
	}
	cout << second;
	return second;
}

int main(){
	int bridge_lenth = 100;
	int weight = 100;
	vector<int> truck_weights;
	truck_weights.push_back(10);
	solution(bridge_lenth, weight, truck_weights);
}