#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int index = 0;
	sort(citations.begin(), citations.end(), greater<int>());
	while (index < citations.size()){
		if (citations[index] <= index)
			break;
		index++;
	}
	return index;
}
