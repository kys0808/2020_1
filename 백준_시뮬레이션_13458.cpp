#include <iostream>
#include <vector>

using namespace std;

long long n;
vector<int> ai;	// 각 인덱스가 i번째 시험장 인원들
long long b, c;
long long answer = 0;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		ai.push_back(tmp);
	}
	cin >> b >> c;

	for (int i = 0; i < ai.size(); i++){
		int total = ai[i];
		total = total - b;
		answer++;
		if (total % c == 0 && total>0){
			answer += total / c;
		}
		if (total%c != 0 && total>0){
			answer += (total / c + 1);
		}
	}
	cout << answer;
}