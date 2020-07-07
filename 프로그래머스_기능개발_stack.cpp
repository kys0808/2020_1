#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int check = 0;
	while (1){
		int pass = 0;
		while (1){
			if (progresses[check] >= 100){
				pass++;
				check++;
				if (check == progresses.size())
					break;
			}
			else
				break;
		}
		for (int i = check; i < progresses.size(); i++){
			progresses[i] += speeds[i];
		}
		if (pass > 0){
			answer.push_back(pass);
		}
		if (check == progresses.size())
			break;
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i]<<endl;
	return answer;
}

int main(){
	vector<int> a;
	a.push_back(93);
	a.push_back(30);
	a.push_back(55);
	vector<int> b;
	b.push_back(1);
	b.push_back(30);
	b.push_back(5);
	solution(a, b);
}