#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <deque>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	stringstream ss;
	deque<int> dq;
	for (int i = 0; i < operations.size(); i++){
		ss.str(operations[i]);
		char order; int num;
		ss >> order;
		ss >> num;
		ss.clear();
		if (order == 'I'){
			dq.push_back(num);
			sort(dq.begin(), dq.end(), less<int >());
		}
		if (order == 'D'){
			if (!dq.empty()){
				if (num == -1){
					dq.pop_front();
				}
				else if (num == 1){
					dq.pop_back();
				}
			}
			if (dq.empty()){
				continue;
			}
		}
	}
	int max_num;
	int min_num;
	if (dq.empty()){
		max_num = 0;
		min_num = 0;
	}
	else{
		max_num = dq.back();
		min_num = dq.front();
	}
	answer.push_back(max_num); answer.push_back(min_num);
	return answer;
}