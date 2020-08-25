#include <iostream>
#include <map>
using namespace std;


int n, m;
map<int, int> parents;

int _find(int num){
	if (parents[num] == 0){	// 번호 배정이 안되어있으면
		return num;
	}
	parents[num] = _find(parents[num]);
	return parents[num];
}
void _merge(int first, int second){
	int first_root = _find(first);
	int second_root = _find(second);
	if (first_root == second_root){
		return;
	}
	parents[first_root] = second_root;
}

int main(){
	scanf_s("%d %d", &n, &m);
	int a, b, c;
	for (int i = 0; i < m; i++){
		scanf_s("%d %d %d", &a, &b, &c);
		if (a == 0){
			_merge(b,c);
		}
		if (a == 1){
			int root_a =_find(b);
			int root_b =_find(c);
			if (root_a == root_b){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
}