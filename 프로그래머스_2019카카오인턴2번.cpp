#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
	return a.size() < b.size();
}
vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<int>> num;
	int index = 2;
	int push_num = 0;
	vector<int> tmp;
	for (int i = index; i < s.size() - 1; i++){
		if (s[i] >= '0' && s[i] <= '9'){
			push_num = (push_num * 10) + (s[i] - '0');
		}
		if (s[i] == ',' &&s[i + 1] != '{'){	// 다음 숫자 이전
			tmp.push_back(push_num);
			push_num = 0;
		}
		if (s[i] == '}'){
			tmp.push_back(push_num);
			push_num = 0;
			num.push_back(tmp);
			tmp.clear();
		}
	}
	sort(num.begin(), num.end(), cmp);	// 갯수 순서대로 정렬


	for (int i = 0; i < num[0].size(); i++){	// 첫번째 수 입력
		answer.push_back(num[0][i]);
	}	
	for (int i = 1; i < num.size(); i++){
		for (int j = 0; j < num[i].size(); j++){
			bool check = false;
			for (int k = 0; k < answer.size(); k++){
				if (answer[k] == num[i][j]){
					check = true;
					break;
				}
			}
			if (check == false){
				answer.push_back(num[i][j]);
			}
		}
	}
	for (int i = 0; i < answer.size(); i++){
		cout << answer[i] << " ";
	}
	cout << endl;


	return answer;
}