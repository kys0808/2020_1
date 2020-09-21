#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int t_size;
int check[10001];
int start_check[10001];

vector<string> tmp_answer;
vector<vector<string>> real_answer;
void back(int depth, string start, vector<vector<string>> tickets){
	if (depth == t_size){
		tmp_answer.push_back(start);
		real_answer.push_back(tmp_answer);
		tmp_answer.pop_back();
		return;
	}
	for (int i = 0; i < tickets.size(); i++){
		string tmp_start = tickets[i][0];
		string tmp_end = tickets[i][1];
		if (depth == 0){
			if (check[i] == 0){
				if (tmp_start == "ICN"){
					check[i] = 1;
					tmp_answer.push_back("ICN");
					back(depth + 1, tmp_end, tickets);
					tmp_answer.pop_back();
					check[i] = 0;
				}
			}
		}
		else{
			if (check[i] == 0){
				if (tmp_start == start){
					check[i] = 1;
					tmp_answer.push_back(tmp_start);
					back(depth + 1, tmp_end, tickets);
					tmp_answer.pop_back();
					check[i] = 0;
				}
			}
		}
	}
}

bool cmp(vector<string> a, vector<string> b){
	for (int i = 0; i < a.size(); i++){
		if (a[i] < b[i]){
			return true;
		}
		else if (a[i] == b[i]){
			continue;
		}
		else{
			return false;
		}
	}
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	t_size = tickets.size();
	back(0,"", tickets);
	sort(real_answer.begin(), real_answer.end(), cmp);
	answer = real_answer[0];
	return answer;
}