#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
// set 시간복잡도 다시 공부!!!
using namespace std;

int m;
vector<int> v;
set<int> s;

void going2(string order){
	if (order == "all"){
		for (int i = 1; i <= 20; i++){
			s.insert(i);
		}
	}
	if (order == "empty"){
		s.clear();
	}
}

void going(string order, int n){
	if (order == "add"){
		s.insert(n);
	}
	if (order == "remove"){
		set<int>::iterator iter;
		iter = s.find(n);
		if (iter != s.end()){	// 있다
			s.erase(iter);
		}
	}
	if (order == "check"){
		set<int>::iterator iter;
		iter = s.find(n);
		if (iter == s.end()){	// 없다
			printf("0\n");
		}
		else{
			printf("1\n");
		}
	}
	if (order == "toggle"){
		set<int>::iterator iter;
		iter = s.find(n);
		if (iter == s.end()){	// 없으면 추가
			s.insert(n);
		}
		else{
			s.erase(iter);
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m;
	for (int i = 0; i < m; i++){
		string order;
		int n;
		cin >> order;
		if (order == "all" || order == "empty"){
			going2(order);
		}
		else{
			cin >> n;
			going(order, n);
		}
	}
}