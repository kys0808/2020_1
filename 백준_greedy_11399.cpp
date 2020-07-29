#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> time;

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		time.push_back(tmp);
	}
	sort(time.begin(), time.end());
	int sum = 0;
	int answer = 0;
	for (int i = 0; i < time.size(); i++){
		time[i] = time[i] + sum;
		sum = time[i];
	}
	for (int i = 0; i < time.size(); i++){
		answer += time[i];
	}
	cout << answer;
}