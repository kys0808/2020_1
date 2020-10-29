#include <string>
#include <vector>
#include <iostream>


using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i<skill_trees.size(); i++){
		vector<bool> check;
		vector<bool> cmp;
		for (int j = 0; j<skill_trees[i].size(); j++){
			for (int k = 0; k<skill.length(); k++){
				if (skill[k] == skill_trees[i][j]){
					cmp.push_back(true);
				}
			}
		}
		while (cmp.size()< skill.length()){
			cmp.push_back(false);
		}
		int check_p = 0;
		for (int j = 0; j<skill_trees[i].size(); j++){
			if (skill_trees[i][j] == skill[check_p]){
				check.push_back(true);
				check_p++;
			}
		}
		while (check.size() < skill.length()){
			check.push_back(false);
		}
		bool answer_check = true;
		for (int j = 0; j<check.size(); j++){
			if (check[j] != cmp[j]){
				answer_check = false;
			}
		}
		if (answer_check == true){
			answer++;
		}

	}
	return answer;
}