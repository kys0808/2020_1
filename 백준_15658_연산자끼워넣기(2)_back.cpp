#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int n;
vector<int> num;
int op[4];
int min_answer = 1000000000;
int max_answer = -1000000000;
void back(int depth, int plus, int minus, int mul, int demul,int result){
	if (depth == n - 1){
		min_answer = min(min_answer, result);
		max_answer = max(max_answer, result);
		return;
	}
	if (plus > 0){
		back(depth + 1, plus - 1, minus, mul, demul,result+num[depth+1]);
	}
	if (minus > 0){
		back(depth + 1, plus, minus - 1, mul, demul,result-num[depth+1]);
	}
	if (mul > 0){
		back(depth + 1, plus, minus, mul - 1, demul,result*num[depth+1]);
	}
	if (demul > 0){
		back(depth + 1, plus, minus, mul, demul - 1,result/num[depth+1]);
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	int tmp_answer = num[0];
	for (int i = 0; i < 4; i++){
		cin >> op[i];
	}
	back(0, op[0], op[1], op[2], op[3],tmp_answer);
	cout << max_answer << '\n';
	cout << min_answer << '\n';
}