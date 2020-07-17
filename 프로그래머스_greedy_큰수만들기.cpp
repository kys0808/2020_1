#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

string solution(string number, int k) {
	int num_len = number.size();
	int t = num_len - k;	// 구하고자 하는 길이
	int start_index = 0;
	vector<char> v;
	while (t > 0){
		int max_num = 0;
		for (int i = start_index; i < num_len - (t - 1); i++){
			if (number[i]>max_num){
				start_index = i;
				max_num = number[i];
			}
		}
		v.push_back(number[start_index]);
		start_index += 1;
		t--;
	}
	string answer = "";
	for (int i = 0; i < v.size(); i++){
		answer.push_back((v[i]));
	}
	cout << answer;
	return answer;
}

int main(){
	string number = "4177252841";
	int k = 4;
	solution(number, k);
}