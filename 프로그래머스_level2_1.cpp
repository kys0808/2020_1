#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	vector<char> tmp[21];
	for (int i = 0; i<skill_trees.size(); i++){
		for (int j = 0; j<skill_trees[i].size(); j++){
			for (int k = 0; k<skill.size(); k++){
				if (skill_trees[i][j] == skill[k]){
					tmp[i].push_back(skill[k]);
				}
			}
		}
		bool check = true;
		for (int j = 0; j<tmp[i].size(); j++){
			cout << tmp[i][j] << " ";
		}
		cout << endl;
		for (int j = 0; j<tmp[i].size(); j++){
			if (tmp[i][j] != skill[j]){
				check = false;
			}
		}
		if (check == true)
			answer++;
	}
	return answer;
}