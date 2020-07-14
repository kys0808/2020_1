#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	for (int i = 1; i <= brown; i++){
		for (int j = 1; j <= brown; j++){
			if (i*j == yellow + brown && i>=j){
				if ((i - 2)*(j - 2) == yellow){
					answer.push_back(i);
					answer.push_back(j);
				}
			}
		}
	}
	for (int i = 0; i < answer.size(); i++){
		cout << answer[i] << endl;
	}
	return answer;
}

int main(){
	solution(10, 2);
}