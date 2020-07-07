#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

stack<int> solution(vector<int> heights) {
	//vector<int> answer;
	stack<int> answer;
	int max_index = heights.size()-1;
	for (int i = max_index ; i >= 0; i--){
		bool check = false;
		for (int j = i - 1; j >= 0; j--){
			if (heights[i] < heights[j]){
				answer.push(j+1);
				check = true;
				break;
			}
		}
		if (check == false){
			answer.push(0);
		}
	}
	for (int i = 0; i < answer.size(); i++){
		cout << answer[i];
	}
	return answer;
}