#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<long long, long long> mp;

long long _find(long long num){
	if (mp[num] == 0){
		return num;
	}
	else{
		mp[num] = _find(mp[num]);	
		// 배정 됐으면 그 번호들 쫓아가서 끝으로 가자
		return mp[num];
	}
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	for (int i = 0; i < room_number.size(); i++){
		long long num = room_number[i];
		if (mp[num] == 0){	// 배정 안됐으면
			answer.push_back(num);
			mp[num] = _find(num+1);	// 다음번호로 배정
		}
		else{
			long long other_num = _find(mp[num]);	
			// 배정되있어서 번호 가리키면 찾아가서 그 다음 번호 가져와
			answer.push_back(other_num);
			mp[other_num] = _find(other_num + 1);
		}
	}
	return answer;
}