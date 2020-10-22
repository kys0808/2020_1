#include <string>
#include <vector>
#include <iostream>

using namespace std;


int num;    // 명령 수
int n;  // 단어의 개수

vector<string> answer[1001];
vector<pair<int, int>> v;

void find_index(vector<string> f_p, vector<string> s_p){
	for (int i = 0; i<f_p.size(); i++){
		for (int j = 0; j<s_p.size(); j++){
			if (f_p[i] == s_p[j]){
				v.push_back({ i, j });  // i는 오리진, j는 new
				break;
			}
		}
	}
}

void make_origin(vector<string> secret, int num){
	for (int i = 0; i<v.size(); i++){
		int origin_index = i;
		int new_index = v[i].second;
		answer[num].push_back(secret[new_index]);
	}
}

int main(){
	cin >> num;
	for (int i = 0; i<num; i++){
		cin >> n;
		vector<string> f_p;
		vector<string> s_p;
		vector<string> secret;
		string tmp;

		for (int j = 0; j<n; j++){
			cin >> tmp;
			f_p.push_back(tmp);
		}
		for (int j = 0; j<n; j++){
			cin >> tmp;
			s_p.push_back(tmp);
		}
		for (int j = 0; j<n; j++){
			cin >> tmp;
			secret.push_back(tmp);
		}
		if (!v.empty()){
			v.clear();
		}
		find_index(f_p, s_p);
		make_origin(secret, i);
	}
	for (int i = 0; i<num; i++){
		for (int j = 0; j<answer[i].size(); j++){
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
}