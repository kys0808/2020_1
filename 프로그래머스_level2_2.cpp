#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int check[101];
vector<int> solution(vector<int> heights) {
	vector<int> answer;
	memset(check, 0, sizeof(check));
	for (int i = heights.size() - 1; i >= 0; i--){
		for (int j = i - 1; j >= 0; j--){
			if (check[i]){
				continue;
			}
			int current = heights[i];
			if (current<heights[j]){
				check[i] = j + 1;
			}
		}
	}
	for (int i = 0; i<heights.size(); i++){
		answer.push_back(check[i]);
	}
	return answer;
}