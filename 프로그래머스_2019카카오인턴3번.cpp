#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

vector<string> tmp[8];
map<string, int> mp;
int answer = 0;
int check_num[8];
int re_num[8][8];
vector<int> ans_v;

set<string> s;

void back(int depth, vector<string> user_id, vector<string> banned_id){
	if (depth == banned_id.size()){
		//시작
		string s_tmp;	// 백트레킹으로 찾은 숫자 조합을 관리
		for (int i = 0; i < 8; i++){
			if (check_num[i]){
				s_tmp += to_string(i);	
				//즉 나타난 조합들 (ex 1 0 2 3  == 0 1 2 3) 을 만들어 주기위해서 check[i]의 i를 string에 포함시켜 문자열 만들고 set에 넣어 중복제거
			}
		}
		s.insert(s_tmp);
		return; 
	}
	for (int i = 0; i < tmp[depth].size(); i++){
		if (!check_num[mp[tmp[depth][i]]]){	// 해당 string이 안나왔으면
			check_num[mp[tmp[depth][i]]] = 1;
			ans_v.push_back(mp[tmp[depth][i]]);
			back(depth + 1, user_id, banned_id);
			ans_v.pop_back();
			check_num[mp[tmp[depth][i]]] = 0;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	for (int i = 0; i < user_id.size(); i++){	// string 마다 번호 부여
		mp.insert(make_pair(user_id[i], i));
	}
	for (int i = 0; i < banned_id.size(); i++){
		for (int j = 0; j < user_id.size(); j++){
			bool check = true;
			for (int k = 0; k < banned_id[i].size(); k++){
				if (banned_id[i].size() == user_id[j].size()){	// 사이즈가 같고
					if (banned_id[i][k] != user_id[j][k]){
						if (banned_id[i][k] != '*'){
							check = false;
							break;
						}
					}
				}
				else{
					check = false;
					break;
				}
			}
			if (check == true){
				tmp[i].push_back(user_id[j]);	// 해당 banned_id 자리에 user_id를 push
			}
		}
	}
	// tmp에 banned_id 별 해당되는 것들 넣어놨음

	back(0, user_id, banned_id);
	answer = s.size();
	return answer;
}
