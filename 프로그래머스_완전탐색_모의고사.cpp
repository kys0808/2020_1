#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> a1;
	vector<int> a2;
	vector<int> a3;
	int len = answers.size();
	for (int i = 0; i < len; i++){
		a1.push_back(i % 5 + 1);
		if (i % 8 == 1)
			a2.push_back(1);
		if (i % 8 == 3)
			a2.push_back(3);
		if (i % 8 == 5)
			a2.push_back(4);
		if (i % 8 == 7)
			a2.push_back(5);
		if (i % 2 == 0)
			a2.push_back(2);
		if (i % 10 == 0 || i % 10 == 1)
			a3.push_back(3);
		if (i % 10 == 2 || i % 10 == 3)
			a3.push_back(1);
		if (i % 10 == 4 || i % 10 == 5)
			a3.push_back(2);
		if (i % 10 == 6 || i % 10 == 7)
			a3.push_back(4);
		if (i % 10 == 8 || i % 10 == 9)
			a3.push_back(5);
	}
	int c1 = 0; int c2 = 0; int c3 = 0;
	for (int i = 0; i < len; i++){
		if (a1[i] == answers[i]) c1++;
		if (a2[i] == answers[i]) c2++;
		if (a3[i] == answers[i]) c3++;
	}

	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(c1, 1));
	pq.push(make_pair(c2, 2));
	pq.push(make_pair(c3, 3));

	int top = 0;
	top = pq.top().first;
	answer.push_back(pq.top().second);
	pq.pop();
	while (!pq.empty()){
		if (pq.top().first == top){
			answer.push_back(pq.top().second);
			pq.pop();
		}
		else break;
	}
	for (int i = 0; i < answer.size();i++)
	cout << answer[i];
	return answer;
}

int main(){
	vector<int> answers;
	answers.push_back(1);
	answers.push_back(3);
	answers.push_back(2);
	answers.push_back(4);
	answers.push_back(2);
	solution(answers);
}
