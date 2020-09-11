#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

// 1:20 => 0:48 // 32분

vector<pair<int, double>> mp;	// stage번호, 실패율
int check[501];				// stage별 도달 사람수

bool cmp(pair<int, double> a ,pair<int, double> b){
	if (a.second < b.second){
		return false;
	}
	else if (a.second == b.second){
		if (a.first < b.first){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return true;
	}
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	sort(stages.begin(), stages.end());	// 일단 정렬

	for (int i = 0; i < stages.size(); i++){
		check[stages[i]]++;	// 각 스테이지별 도달 사람 수 체크
	}

	double total_num = stages.size();	// 스테이지에 도달한 사람
	// 마지막 스테이지는 따로처리하자
	for (int i = 1; i < N; i++){
		double total = check[i];
		double fault = 0;
		if (total_num >0)
			fault = (total / total_num);
		else{
			fault = 0;
		}
		mp.push_back({ i, fault });
		total_num -= total;
	}
	double last_total_num = check[N] + check[N +1];	// 마지막 stage 도달한 사람수
	double stop_num = check[N];						// 마지막 stage에 멈춘 사람수
	double last_fault = 0;
	if (last_total_num >0)
		last_fault = (stop_num) / last_total_num;
	else{
		last_fault = 0;
	}
	mp.push_back({ N, last_fault });
	sort(mp.begin(), mp.end(), cmp);
	for (int i = 0; i < mp.size(); i++){
		answer.push_back(mp[i].first);
	}
	return answer;
}