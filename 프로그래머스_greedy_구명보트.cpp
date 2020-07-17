#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;
int check[50001];
int size = 0;
int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end(),greater<int>());
	int start = 0;
	int end = people.size() - 1;
	for (int i = 0; i < people.size(); i++)
		cout << people[i] << endl;
	while (start < end){
		cout << start << " " << end << " " << people[start] + people[end] << endl;
		if (people[start] + people[end] <= limit){
			start++;
			end--;
			answer++;
		}
		else{
			start++;
			answer++;
		}
	}
	if (start == end){
		answer++;
	}
	cout << answer;
	return answer;
}

int main(){
	vector<int> people = { 70,50, 80, 50 };
	int limit = 100;
	solution(people, limit);
}