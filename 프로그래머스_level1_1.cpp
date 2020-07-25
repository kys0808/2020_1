#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long start = 0;
	long long end = n*(long long)(times[times.size() - 1]);

	sort(times.begin(), times.end());
	answer = end;
	while (start <= end){
	long long check = 0;
		long long mid = (start + end) / 2;
		for (int i = 0; i < times.size(); i++){
				check += mid / times[i];
		}
		if (check < n){
			start = mid + 1;
		}
		if (check >= n){
			if (answer >= mid){
				answer = mid;
				cout << answer << endl;
			}
			end = mid - 1;
		}
	}
	cout << answer;
	return answer;
}

int main(){
	int n = 6;
	vector<int> times = { 7, 10 };
	solution(n, times);
}