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
	sort(forsort.begin(), forsort.end());	// sort �ϱ�
	int start = 1;
	int end = forsort[forsort.size() - 1];
	// �̺� Ž�� ���� �� �� - ũ�⸦ �̿�
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
			if (count >= k){	// ã�ٰ� count == k �Ǹ� �츮�� ã�����ϴ� answer
				end = mid - 1;
				answer = mid;
				break;
			}
		}
		if (count < k){	// ã�ٰ� count <k �� �츮�� ã���� �ϴ°� �ƴϹǷ� start �� ����
			start = mid + 1;
		}
	}
	return answer;
}

int main(){
	vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
	int k = 3;
	solution(stones, k);
}