#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;


int main(){
	string s;
	cin >> s;
	// ¾ËÆÄºª 28°³ (0-27)
	map<int, int> mp;

	for (int i = 0; i<s.length(); i++){
		int key = -1;
		if (s[i] >= 'A' && s[i] <= 'Z'){
			key = s[i] - 'A';
		}
		else{
			key = s[i] - 'a';
		}
		if (mp[key] == 0){
			mp[key] = 1;
		}
		else{
			mp[key]++;
		}
	}
	int max_count = 0;
	for (int i = 0; i<27; i++){
		max_count = max(mp[i], max_count);
	}
	vector<int> v;
	for (int i = 0; i<27; i++){
		if (max_count == mp[i]){
			v.push_back(i);
		}
	}
	if (v.size() == 1){
		char answer = 'A' + v.front();
		cout << answer << endl;
	}
	else{
		cout << '?' << endl;
	}


}
