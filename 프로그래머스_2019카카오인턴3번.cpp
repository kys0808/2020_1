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
		//����
		string s_tmp;	// ��Ʈ��ŷ���� ã�� ���� ������ ����
		for (int i = 0; i < 8; i++){
			if (check_num[i]){
				s_tmp += to_string(i);	
				//�� ��Ÿ�� ���յ� (ex 1 0 2 3  == 0 1 2 3) �� ����� �ֱ����ؼ� check[i]�� i�� string�� ���Խ��� ���ڿ� ����� set�� �־� �ߺ�����
			}
		}
		s.insert(s_tmp);
		return; 
	}
	for (int i = 0; i < tmp[depth].size(); i++){
		if (!check_num[mp[tmp[depth][i]]]){	// �ش� string�� �ȳ�������
			check_num[mp[tmp[depth][i]]] = 1;
			ans_v.push_back(mp[tmp[depth][i]]);
			back(depth + 1, user_id, banned_id);
			ans_v.pop_back();
			check_num[mp[tmp[depth][i]]] = 0;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	for (int i = 0; i < user_id.size(); i++){	// string ���� ��ȣ �ο�
		mp.insert(make_pair(user_id[i], i));
	}
	for (int i = 0; i < banned_id.size(); i++){
		for (int j = 0; j < user_id.size(); j++){
			bool check = true;
			for (int k = 0; k < banned_id[i].size(); k++){
				if (banned_id[i].size() == user_id[j].size()){	// ����� ����
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
				tmp[i].push_back(user_id[j]);	// �ش� banned_id �ڸ��� user_id�� push
			}
		}
	}
	// tmp�� banned_id �� �ش�Ǵ� �͵� �־����

	back(0, user_id, banned_id);
	answer = s.size();
	return answer;
}
