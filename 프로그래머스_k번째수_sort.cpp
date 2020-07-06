#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	for (int i = 0; i < citations.size(); i++){
		int check1 = 0;
		int check2 = 0;
		for (int j = 0; j < citations.size(); j++){
			if (citations[i] <= citations[j]){
				check1++;
			}
			else
				check2++;
		}
		if (check1 >= citations[i] && check2 <= citations[i]){
			if (answer < citations[i]){
				answer = citations[i];
			}
		}
	}
	cout << answer;
	return answer;
}

int main(){
	vector<int> citations;

	solution(citations);
}