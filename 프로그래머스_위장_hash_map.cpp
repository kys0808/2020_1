#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


int solution(vector<vector<string>> clothes) {
	int answer = 0;
	unordered_map<string, int> mp;
	for (auto x : clothes){
		if (mp.find(x[1]) == mp.end())
			mp.insert(make_pair(x[1], 1));
		else
			mp[x[1]]++;
	}
	unordered_map<string, int>::iterator iter;
	for (iter = mp.begin(); iter != mp.end(); iter++){
		answer += iter->second;
	}
	return answer;
}