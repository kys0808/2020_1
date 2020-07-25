#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

string solution(string s) {
	string answer = "";
	vector<char> v;
	for (auto x : s){
		v.push_back(x);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (auto x : v)
		answer.push_back(x);
	return answer;
}