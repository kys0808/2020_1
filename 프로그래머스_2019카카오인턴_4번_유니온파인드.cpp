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
		// ���� ������ �� ��ȣ�� �Ѿư��� ������ ����
		return mp[num];
	}
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	for (int i = 0; i < room_number.size(); i++){
		long long num = room_number[i];
		if (mp[num] == 0){	// ���� �ȵ�����
			answer.push_back(num);
			mp[num] = _find(num+1);	// ������ȣ�� ����
		}
		else{
			long long other_num = _find(mp[num]);	
			// �������־ ��ȣ ����Ű�� ã�ư��� �� ���� ��ȣ ������
			answer.push_back(other_num);
			mp[other_num] = _find(other_num + 1);
		}
	}
	return answer;
}