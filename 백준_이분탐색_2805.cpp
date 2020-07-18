#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n, m;
vector<long long> tree;

long long solution(vector<long long> tree, long long n, long long m){
	long long answer = 0;
	long long start = 0;
	long long end = 1000000000;
	while(start <= end){
		long long sum = 0;
		long long mid = (start + end) / 2;
		for (long long i = 0; i < n;i++){
			if (tree[i] > mid){
				sum += (tree[i] - mid);
			}
		}
		if (m<=sum){
			if (answer <mid)
				answer = mid;
			start = mid + 1;
		}
		if(m>sum){
			end = mid - 1;
		}
	}
	cout << answer;
	return answer;
}

int main(){
	cin >> n >> m;
	int mx = 0;
	for (int i = 0; i < n; i++){
		long long tmp;
		cin >> tmp;
		tree.push_back(tmp);
	}
	sort(tree.begin(), tree.end());
	long long answer = solution(tree,n,m);
}