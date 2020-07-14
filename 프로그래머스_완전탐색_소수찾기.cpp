#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <cmath>
using namespace std;

int solution(string numbers) {
	int answer=0;
	sort(numbers.begin(), numbers.end(),greater<int>());
	int to_num = stoi(numbers);
	priority_queue<int> prime_num;
	for (int i = 2; i <= to_num; i++){
		int prime_count = 0;
		for (int j = 2; j <= sqrt(i); j++){
			if (i%j == 0)
				prime_count++;
		}
		if (prime_count == 0){
			prime_num.push(i);
		}
	}
	int number_count[10];

	for (int i = 0; i < 10; i++){
		number_count[i] = -1;
	}
	for (int i = 0; i < numbers.size(); i++){
		number_count[numbers[i] - '0']++;
	}

	while (!prime_num.empty()){
		int tmp_count[10];
		for (int i = 0; i < 10; i++){
			tmp_count[i] = number_count[i];
		}
		string test_num;
		test_num = to_string(prime_num.top());
		bool check = true;
		for (int i = 0; i < test_num.size(); i++){
			if (tmp_count[test_num[i]-'0'] == -1){
				prime_num.pop();
				check = false;
				break;
			}
			else{
				tmp_count[test_num[i]-'0']--;
			}
		}
		if (check == true){
			answer++;
			prime_num.pop();
		}
	}
	cout << answer << endl;
	return answer;
}

int main(){
	string numbers = "11711";
	solution(numbers);
}

