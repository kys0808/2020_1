#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


/*
이분탐색 방법
- 전제조건 = sort가 되어있어야한다.
- 시간 복잡도는 1 / 2씩 줄어들기 때문에 log(n)
int start =0;
int end = 범위의 최대값;

while (start <= end){
	int mid = (start+end)/2;
	int sum = (조건에 맞게);
	if (sum > mid){
		end = mid - 1;	
		// 찾고자 하는 값보다 크기 때문에 end를 mid-1로 줄여야한다.
	}
	if (sum < mid){
		start = mid + 1;
		// 찾고자 하는 값보다 작기 때문에 start를 mid+1로 증가
	}
}
*/



int solution(vector<int> budgets, int M) {
	int answer = 0;
	int max = 0;
	long sum = 0;
	sort(budgets.begin(), budgets.end());
	for (auto x : budgets){
		sum += x;
	}
	if (sum < M){
		answer = budgets[budgets.size() - 1];
		return answer;
	}
	int tmp = 0;
	int start = 0;
	int end = 100000;
	while (start <= end){
		int mid = (start + end) / 2;
		sum = 0;
		for (int i = 0; i < budgets.size(); i++){
			if (budgets[i] > mid){
				sum += mid*(budgets.size() - 1 - (i - 1));
				break;
			}
			else{
				sum += budgets[i];
			}
		}
		if (sum > M){
			end = mid - 1;
		}
		if (sum < M){
			answer = mid;
			start = mid + 1;
		}
		if (sum == M)
			return mid;
		cout << sum << " " << M << endl;
	}
	cout << answer;
	return answer;
}

int main(){
	vector<int> v = { 120, 110, 140, 150 };
	int M = 485;
	solution(v, M);
}