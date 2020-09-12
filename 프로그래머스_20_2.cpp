#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
using namespace std;

int check[30];
string tmp;
map<string, int> mp;
int max_value[30];	// 각 코스요리 개수별 최대갯수
vector<string> tmp_answer[30];	// 각 코스요리 개수별 정답 가능 vector

void back(int depth, int target, int index, string orders){
	if (depth == target){
		if (mp.count(tmp) == 0){	// 해당키 없으면
			mp.insert({ tmp, 1 });
		}
		else{
			mp[tmp]++;
		}
		return;
	}
	for (int i = index; i < orders.size(); i++){
		if (check[i] == 0){
			check[i] = 1;
			tmp += orders[i];
			back(depth + 1, target, i, orders);
			tmp.pop_back();
			check[i] = 0;
		}
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	for (int i = 0; i < orders.size(); i++){
		sort(orders[i].begin(), orders[i].end(), less<char>());
	}

	for (int i = 0; i < course.size(); i++){

		for (int j = 0; j < orders.size(); j++){
			back(0, course[i], 0, orders[j]);
		}
		// 하나의 course 개수에 대해서 만들었으면 map에 추가 끝난상태 이제 value값 최대 구해야지
		map<string, int>::iterator iter;
		for (iter = mp.begin(); iter != mp.end(); iter++){
			if (iter->first.size() == course[i]){	// 현재 찾고있는 코스의 갯수랑 같으면
				max_value[course[i]] = max(max_value[course[i]], iter->second);
			}
		}
		for (iter = mp.begin(); iter != mp.end(); iter++){
			if (iter->first.size() == course[i]){
				if (max_value[course[i]] == iter->second && max_value[course[i]]>1){
					tmp_answer[course[i]].push_back(iter->first);
				}
			}
		}
	}
	for (int i = 0; i < 30; i++){
		if (!tmp_answer[i].empty()){
			for (int j = 0; j < tmp_answer[i].size(); j++){
				answer.push_back(tmp_answer[i][j]);
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}