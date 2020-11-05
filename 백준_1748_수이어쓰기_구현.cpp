#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;


long long n; // n�� 100,000,000
int answer = 0;

int main(){
	cin >> n;
	// 1 -9 / 10 - 99 / 100 - 999/ 1000-9999/
	// 9   / (100-9) / (1000- 99)

	//1. n�� �ڸ��� ���ϱ�
	int size = 0;
	int tmp = n;
	while (tmp > 0){
		size++;
		tmp = tmp / 10;
	}
	// 2. �� �ڸ��� �������� �� ���� ���ϱ�
	// 100 �� size = 3 �̴ϱ� size 2���� ���� �ٴ��ϱ�
	for (int i = 1; i<size; i++){
		if (i == 1){
			answer += 9;
		}
		else{
			answer += ((pow(10, i) - 1) - (pow(10, i - 1) - 1)) * (i);
		}
	}

	int rest = (n - pow(10, size - 1) + 1);

	answer += (rest)*(size);
	cout << answer << endl;

}