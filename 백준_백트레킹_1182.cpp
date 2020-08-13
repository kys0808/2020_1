#include <iostream>

using namespace std;


int n, s;
int answer;
int sum;
int k[100000];
void back(int idx){
	sum += k[idx];
	if (sum == s){
		answer++;
		return;
	}
	if (idx >= n)
		return;
	back(idx + 1);
	sum -= k[idx];
	back(idx + 1);
}

int main(){
	cin >> n >> s;
	for (int i = 0; i < n; i++){
		cin >> k[i];
	}
	back(0);
	cout << answer << endl;
}