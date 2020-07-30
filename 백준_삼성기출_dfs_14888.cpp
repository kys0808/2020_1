#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
vector<int> num;
int oper[4];

int max_num = -1000000000;
int min_num = 1000000000;
// 문제점 oper가 count 때마다 이어지지 않음;;
void dfs(int start, int a, int b, int c, int d, int sum, int count){
	if (count == n -1){
		max_num = max(max_num, sum);
		min_num = min(min_num, sum);
		return;
	}
	if (count == 0){
		if (start == 0){
			if (a < oper[0]){
				sum = num[0] + num[1];
				a = a + 1;
			}
			else return;
		}
		if (start == 1){
			if (b < oper[1]){
				sum = num[0] - num[1];
				b = b + 1;
			}
			else return;
		}
		if (start == 2){
			if (c < oper[2]){
				sum = num[0] * num[1];
				c = c + 1;
			}
			else return;
		}
		if (start == 3){
			if (d < oper[3]){
				if (num[0] > 0){
					sum = num[0] / num[1];
					d = d + 1;
				}
				else{
					sum = (-num[0]) / num[1];
					sum = -sum;
					d = d + 1;
				}
			}
			else return;
		}
		count += 1;
		for (int i = 0; i < 4; i++){
			dfs(i, a, b, c, d, sum, count);
		}
	}

	else{
		if (start == 0){
			if (a < oper[0]){
				sum = sum + num[count + 1];
				a = a + 1;
			}
			else return;
		}
		if (start == 1){
			if (b < oper[1]){
				sum = sum - num[count + 1];
				b = b + 1;
			}
			else return;
		}
		if (start == 2){
			if (c < oper[2]){
				sum = sum * num[count + 1];
				c = c + 1;
			}
			else return;
		}
		if (start == 3){
			if (d < oper[3]){
				if (sum > 0){
					sum = sum / num[count + 1];
					d = d + 1;
				}
				else{
					sum = (-sum) / num[count + 1];
					sum = -sum;
					d = d + 1;
				}
			}
			else return;
		}
		count += 1;
		for (int i = 0; i < 4; i++){
			dfs(i, a, b, c, d, sum, count);
		}
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}

	for (int i = 0; i < 4; i++){
		int tmp;
		cin >> tmp;
		if (tmp > 0)
			oper[i] = tmp;
	}
	for (int i = 0; i < 4; i++){
		dfs(i, 0,0,0,0, 0, 0);
	}
	cout << max_num << endl;
	cout << min_num << endl;

}