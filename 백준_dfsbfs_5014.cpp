#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int check[1000001];

int main(){
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	queue<int> tmp;
	tmp.push(s);
	check[s] = 1;
	while (!tmp.empty()){
		int current = tmp.front();
		if (current == g){
			break;
		}
		tmp.pop();
		int next = current + u;
		if (next >= 1 && next <= f){
			if (!check[next]){
				tmp.push(next);
				check[next] = check[current] + 1;
			}
		}
		next = current - d;
		if (next >= 1 && next <= f){
			if (!check[next]){
				tmp.push(next);
				check[next] = check[current] + 1;
			}
		}
	}
	if (check[g]){
		cout << check[g] - 1;
	}
	else{
		cout << "use the stairs";
	}
}