#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


/*
�̺�Ž�� ���
- �������� = sort�� �Ǿ��־���Ѵ�.
- �ð� ���⵵�� 1 / 2�� �پ��� ������ log(n)
int start =0;
int end = ������ �ִ밪;

while (start <= end){
	int mid = (start+end)/2;
	int sum = (���ǿ� �°�);
	if (sum > mid){
		end = mid - 1;	
		// ã���� �ϴ� ������ ũ�� ������ end�� mid-1�� �ٿ����Ѵ�.
	}
	if (sum < mid){
		start = mid + 1;
		// ã���� �ϴ� ������ �۱� ������ start�� mid+1�� ����
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