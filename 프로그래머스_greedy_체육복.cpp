#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

int arr[31];
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	for (int i = 0; i < n; i++){
		arr[i]++;
	}
	for (int i = 0; i < lost.size(); i++){
		int status = lost[i] - 1;
		arr[status]--;
	}
	for (int i = 0; i < reserve.size(); i++){
		int status = reserve[i] - 1;
		arr[status]++;
	}
	for (int i = 0; i < n; i++){
		if (arr[i] == 0 && i > 0 && arr[i - 1] == 2){
			arr[i]++; arr[i - 1]--;
		}
		if (arr[i] == 0 && i < n && arr[i + 1] == 2){
			arr[i]++; arr[i + 1]--;
		}
	}
	int lost_p = 0;
	for (int i = 0; i < n; i++){
		if (arr[i] == 0)
			lost_p++;
	}
	answer = n - lost_p;
	cout << answer;
	return answer;
}

int main(){
	vector<int> lost = { 2, 4 };
	vector<int> reserve = { 1, 3, 5 };
	int n = 5;
	solution(5, lost, reserve);
}