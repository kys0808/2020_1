#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int check[100001];
bool cmp(pair<int, int> &a, pair<int, int> &b){
	int first = abs(a.first - a.second);
	int second = abs(b.first - b.second);
	if (first < second){
		return true;
	}
	else if (first == second){
		return a.first < b.first;
	}
	else{
		return false;
	}
}
vector<int> solution(vector<string> gems) {
	set<string> kindofgems;
	for (int i = 0; i < gems.size(); i++){
		kindofgems.insert(gems[i]);	// �ߺ� ���� �� ������
	}
	map<string, int> mp;
	vector<pair<int, int>> tmp;
	vector<int> answer;
	int start = 0; int end = 0;
	int diff = gems.size();
	// �� ������
	while (1){
		if (mp.size() == kindofgems.size()){	// ���� �ٴ�ҳ�?
			// ������� ���
			tmp.push_back({ start+1, end });
			// �κ��� ��á���ϱ� start++ �Ұǵ� mpó���ϰ� ����
			if (mp[gems[start]] == 1){
				mp.erase(gems[start]);
				start++;
			}
			else if (mp[gems[start]] > 1){	// 1������ ������ ������ �ٿ�
				mp[gems[start]]--;
				start++;
			}
		}
		else if (end == gems.size()){
			break;	// ������ ������ ����
		}
		else{	// �� ��Ȳ �ƴϸ� end ++;
			mp[gems[end]]++;
			end++;
		}
	}
	sort(tmp.begin(), tmp.end(), cmp);
	answer.push_back(tmp[0].first);
	answer.push_back(tmp[0].second);
	return answer;
}

int main(){
	vector<string> gems = { "AA", "AB", "AC", "AA", "AC" };
	solution(gems);
}