#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> lotto;
vector<int> num;
void dfs(int start, int count){
	if (count == 6){
		for (int i = 0; i < 6; i++){
			cout << lotto[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = start; i < num.size(); i++){
		lotto.push_back(num[i]);
		dfs(i+1, count + 1);
		lotto.pop_back();
	}
}

int main(){
	while (1){
		cin >> k;
		if (k == 0){
			break;
		}
		else{
			while(!num.empty()){
				num.pop_back();
			}
			while(!lotto.empty()){
				lotto.pop_back();
			}
			for (int i = 0; i < k; i++){
				int tmp;
				cin >> tmp;
				num.push_back(tmp);
			}
			dfs(0, 0);
			cout << endl;
		}
	}
}