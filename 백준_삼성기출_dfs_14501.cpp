#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int plan[16];
int pay[16];
int n;
int answer = 0;
void dfs(int day, int sum){
	if (day == n + 1){
		answer = max(answer, sum);
		return;
	}
	if (day + plan[day] <= n + 1){
		dfs(day + plan[day], sum + pay[day]);
	}
	if (day + 1 <= n + 1){
		dfs(day + 1, sum);
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		int day, charge;
		cin >> day >> charge;
		plan[i] = day;
		pay[i] = charge;
	}
	dfs(1, 0);
	cout << answer;
}