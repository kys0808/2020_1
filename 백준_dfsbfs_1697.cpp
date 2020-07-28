#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;

int move_idx[2] = { -1, 1 };
int check[100001];
int main(){
	cin >> n >> k;
	queue<int> tmp;
	tmp.push(n);
	check[n] = 1;
	while (!tmp.empty()){
		int current = tmp.front();
		if (current == k){
			break;
		}
		tmp.pop();
		int next = current * 2;
		if (next >= 0 && next <= 100000){
			if (!check[next]){
				check[next] = check[current] + 1;
				tmp.push(next);
			}
		}
		for (int i = 0; i < 2; i++){
			int next = current + move_idx[i];
			if (next >= 0 && next <= 100000){
				if (!check[next]){
					check[next] = check[current] + 1;
					tmp.push(next);
				}
			}
		}
	}
	cout << check[k] - 1;
}