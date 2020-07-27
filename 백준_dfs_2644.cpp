#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[101];
int check[101];

int n;
int a, b;
int c;
int answer = -1;
void dfs(int start,int target, int sum){
	check[start] = 1;
	if (start == target){
		answer = sum;
		return ;
	}
	for (int i = 0; i < graph[start].size(); i++){
		int next = graph[start][i];
		if (!check[next]){
			sum++;
			dfs(next, target,sum);
			sum--;
		}
	}
	return;
}

int main(){
	cin >> n >> a >> b >> c;
	while (c--){
		int parent, child;
		cin >> parent >> child;
		graph[parent].push_back(child);
		graph[child].push_back(parent);
	}	
	dfs(a,b,0);
	cout << answer;
}