#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> p_man, n_man, p_wman, n_wman;
// prioirty_queue<T, vector<T>, greater<T>> pq;
// prioirty_queue<T, vector<T>, less<T>> pq;


int answer = 0;

int main(){
	int n;
	cin >> n;
	for (int i = 0; i<n; i++){
		int h;
		cin >> h;
		if (h <0){
			n_man.push(abs(h));
		}
		else{
			p_man.push(h);
		}
	}
	for (int i = 0; i<n; i++){
		int h;
		cin >> h;
		if (h<0){
			n_wman.push(abs(h));
		}
		else{
			p_wman.push(h);
		}
	}

	while (1){
		if (p_wman.empty() || n_man.empty()){
			break;
		}
		else{
			int man_h = n_man.top();
			int wman_h = p_wman.top();
			n_man.pop();
			if (man_h >wman_h){
				answer++;
				p_wman.pop();
			}
		}
	}
	while (1){
		if (p_man.empty() || n_wman.empty()){
			break;
		}
		else{
			int man_h = p_man.top();
			int wman_h = n_wman.top();
			n_wman.pop();
			if (man_h < wman_h){
				answer++;
				p_man.pop();
			}
		}
	}

	cout << answer << endl;

}