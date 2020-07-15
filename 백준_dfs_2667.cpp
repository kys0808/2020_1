#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

int arr[26][26];
int check[26][26];

// 모든 경우의수 dfs로 돌아봄

void dfs(int start_i, int start_j, int num){
	if (!check[start_i][start_j]){
		check[start_i][start_j] = 1;
		if (arr[start_i][start_j]){
			arr[start_i][start_j] = num;
			dfs(start_i + 1, start_j, num);
			dfs(start_i, start_j + 1, num);
			if (start_i > 0)
				dfs(start_i - 1, start_j, num);
			if (start_j > 0)
				dfs(start_i, start_j - 1, num);
		}
	}
	return ;
}

int main(){
	int n;
	cin >> n;
	string row;
	for (int i = 0; i < n; i++){
		cin >> row;
		for (int j = 0; j < row.size(); j++){
			int index = row[j] -'0';
			arr[i][j] = index;
		}
	}
	int num = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			dfs(i, j, num);
			num++;
		}
	}
	int count[10000];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (arr[i][j])
				count[arr[i][j]]++;
		}
	}
	int check = 0;
	for (int i = 0; i < 10000; i++){
		if (count[i] >0){
			check++;
		}
	}
	cout << check << endl;
	sort(count, count + 10000);
	for (int i = 0; i < 10000; i++){
		if (count[i] >0){
			cout << count[i] << endl;
		}
	}
}
