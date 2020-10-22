#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>


using namespace std;

// pq 시간복잡도는 push 일 때 logN
// sort() 시간복잡도는 NlogN 퀵소트

// pq 정렬법 1. struct 와 연산자 오버로딩
struct N{
	int abs_num;
	int num;
};

bool operator< (N a, N b){
	if (a.abs_num < b.abs_num){
		return false;
	}
	else if (a.abs_num == b.abs_num){
		if (a.num < b.num){
			return false;
		}
		else{
			return true;
		}
	}
	else{
		return true;
	}
}
priority_queue<N> pq;

// pq 정렬법 2. priority_queue< 자료형, vector<자료형>, greater<자료형>> pq; 로
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> v;   // first -abs second - origin




int n;

void pop_v(long long num){
	long long abs_num;
	abs_num = abs(num);

	if (pq.size() != 0){
		//cout<<v.top().second<<endl;
		//v.pop();
		cout << pq.top().num << endl;
		pq.pop();
	}
	else{
		cout << 0 << endl;
	}

}

void push_v(long long num){
	long long abs_num;
	if (num <0){
		abs_num = -num;
	}
	else{
		abs_num = num;
	}
	N push_n;
	push_n.abs_num = abs_num;
	push_n.num = num;
	pq.push(push_n);
	//v.push({abs_num,num});
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i<n; i++){
		long long num;
		cin >> num;
		if (num == 0){
			pop_v(num);
		}
		else{
			push_v(num);
		}
	}
}