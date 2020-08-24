#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 200000001;
	vector<int> forsort;
	for (int i = 0; i < stones.size(); i++){
		forsort.push_back(stones[i]);
	}
	sort(forsort.begin(), forsort.end());	// sort 하기
	int start = 1;
	int end = forsort[forsort.size() - 1];
	// 이분 탐색 진행 할 것 - 크기를 이용
	while (start <= end){
		int mid = (start + end) / 2;
		int count = 0;
		for (int i = 0; i < stones.size(); i++){
			if (stones[i] - mid <= 0){
				count++;
			}
			else{
				count = 0;
			}
			if (count >= k){
				end = mid - 1;
				break;
			}
		}
		if (count < k){
			start = mid + 1;
		}
	}
	answer = start;
	return answer;
}

int main(){
	vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
	int k = 3;
	solution(stones, k);
}