#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	vector<int> tmp_arr;
	for (int i = 0; i<arr1.size(); i++){
		int tmp_push = arr1[i] | arr2[i];
		tmp_arr.push_back(tmp_push);
	}
	stack<int> st;
	vector<string> tmp_answer;

	for (int i = 0; i<tmp_arr.size(); i++){
		string tmp_string;
		int check = tmp_arr[i];
		while (check){
			st.push(check % 2);
			check = check / 2;
		}
		while (st.size() <n){
			st.push(0);
		}
		while (!st.empty()){
			tmp_string += to_string(st.top());
			st.pop();
		}
		tmp_answer.push_back(tmp_string);
	}

	for (int i = 0; i<tmp_answer.size(); i++){
		string real_push;
		for (int j = 0; j<tmp_answer[i].size(); j++){
			if (tmp_answer[i][j] == '1'){
				real_push += ('#');
			}
			else if (tmp_answer[i][j] == '0'){
				real_push += (' ');
			}
		}
		answer.push_back(real_push);
	}
	return answer;
}