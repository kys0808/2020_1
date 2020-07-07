#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> tmp;
	for (auto x : completion){
		if (tmp.find(x) == tmp.end()){
			tmp.insert(make_pair(x, 1));
		}
		else{
			int show = tmp.find(x)->second;
		}
	}
	for (auto y : participant){
		if (tmp.find(y)->second == 0){
			answer.push_back(y.data);
			tmp.erase(y);
		}
		else{
			tmp.find(y)->second--;
		}
	}
	return answer;
}