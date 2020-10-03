#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;


map<string, int> mp;
map<string, int> g_count;
set<string> name;
vector<pair<string, int>> v;

bool cmp(pair<string, int> a, pair<string, int> b){
	if (a.second >= b.second){
		return true;
	}
	else{
		return false;
	}
}

bool sort_cmp(pair<pair<string, int>, int> a, pair<pair<string, int>, int> b){
	if (a.first.second > b.first.second){
		return true;
	}
	else if (a.first.second == b.first.second){
		if (a.second < b.second){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	for (int i = 0; i < genres.size(); i++){
		name.insert(genres[i]);
		if (mp[genres[i]]){
			mp[genres[i]] += plays[i];
		}
		else{
			mp[genres[i]] = plays[i];
		}
		if (g_count[genres[i]]){
			g_count[genres[i]] += 1;
		}
		else{
			g_count[genres[i]] = 1;
		}
	}
	set<string>::iterator iter;
	iter = name.begin();
	for (; iter != name.end(); iter++){
		v.push_back({ *iter, mp[*iter] });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++){
		cout << v[i].first << " " << v[i].second << endl;
	}
	vector<pair<pair<string, int>, int>> real;	// 장르명,재생수,index
	for (int i = 0; i < genres.size(); i++){
		real.push_back({ { genres[i], plays[i] }, i });
	}
	sort(real.begin(), real.end(), sort_cmp);
	for (int i = 0; i < v.size(); i++){
		int count = 0;
		for (int j = 0; j < real.size(); j++){
			if (count == 2){
				break;
			}
			if (g_count[v[i].first] == 1){
				if (count == 1){
					break;
				}
			}
			if (v[i].first == real[j].first.first){
				answer.push_back(real[j].second);
				count++;
			}
		}
	}

	return answer;
}