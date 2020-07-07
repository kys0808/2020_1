#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 1;
	bool check = false;
	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++){
		q.push(make_pair(priorities[i], i));
	}
	while (1){
		for (int i = 0; i < priorities.size(); i++){
			if (priorities[i] > q.front().first){
				q.push(make_pair(q.front().first, q.front().second));
				q.pop();
				answer++;
				check = true;
				break;
			}
		}
		if (check == false){
			if (location == q.front().second){
				cout << answer;
				return answer;
			}
			else{
				q.push(make_pair(q.front().first, q.front().second));
				q.pop();
				answer++;
			}
		}
	}
}
int main(){
	vector<int> priorities;
	priorities.push_back(2); priorities.push_back(1);
	priorities.push_back(3); priorities.push_back(2);
	int location = 2;
	solution(priorities, location);
}