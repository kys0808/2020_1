#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#include <deque>
using namespace std;

vector<long long> num;
vector<char> oper;
vector<char> prime_oper;
set<char> real_oper;

int check_oper[1001];
int use_oper[55];

int check_num[55];
int parents[55];

long long answer;

int _find(int num){
	if (parents[num] == num){
		return num;
	}
	else{
		parents[num] = _find(parents[num]);
	}
}

void _merge(int a, int b){
	cout << "_merge" << endl;
	int first = _find(parents[a]);
	int second = _find(parents[b]);
	cout << first << " " << second << endl;
	if (first == second){
		return;
	}
	else{
		parents[second] = first;
	}
}

void solve(){
	for (int i = 0; i < num.size(); i++){
		parents[i] = i;	// ���� �ʱ�ȭ
	}
	vector<long long> tmp;
	for (int i = 0; i < num.size(); i++){
		//cout << num[i] << " ";
		tmp.push_back(num[i]);
	}
	//cout << endl;

	cout << "start" << endl;
	for (int i = 0; i < prime_oper.size(); i++){
		cout << prime_oper[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < prime_oper.size(); i++){	// �켱���� ���� ���� ���� ������ �ϳ��� ���鼭 ������ڰ�
		for (int j = 0; j < oper.size(); j++){
			if (prime_oper[i] == oper[j]){
				if (oper[j] == '+'){	// ������? �׷� ���� �����غ��ڰ�
					cout << j << " " << parents[j] << " " << _find(parents[j]) << endl;
					int first_idx = _find(parents[j]);
					int second_idx = _find(parents[j + 1]);
					//cout << tmp[first_idx] << " " << tmp[second_idx] << endl;;
					tmp[first_idx] = tmp[first_idx] + tmp[second_idx];	// ���ʿ� ����
					tmp[second_idx] = 0;
					cout << first_idx << " " << second_idx << endl;
					_merge(first_idx, second_idx);
					cout << first_idx << " " << second_idx << endl;
					for (int k = 0; k < tmp.size(); k++){
					cout << tmp[k] << " ";
					}
					cout << endl;
					for (int k = 0; k < num.size(); k++){
					cout << parents[k] << " ";
					}
					cout << endl;
				}
				if (oper[j] == '-'){	// ������? �׷� ���� �����غ��ڰ�
					int first_idx = _find(parents[j]);
					int second_idx = _find(parents[j + 1]);
					//cout << tmp[first_idx] << " " << tmp[second_idx] << endl;;
					tmp[first_idx] = tmp[first_idx] - tmp[second_idx];	// ���ʿ� ����
					tmp[second_idx] = 0;

					_merge(first_idx, second_idx);

					cout << first_idx << " " << second_idx << endl;
					for (int k = 0; k < tmp.size(); k++){
						cout << tmp[k] << " ";
					}
					cout << endl;
					for (int k = 0; k < num.size(); k++){
						cout << parents[k] << " ";
					}
					cout << endl;
				}
				if (oper[j] == '*'){	// ������? �׷� ���� �����غ��ڰ�
					int first_idx = _find(parents[j]);
					int second_idx = _find(parents[j + 1]);
					//cout << tmp[first_idx] << " " << tmp[second_idx] << endl;;
					tmp[first_idx] = tmp[first_idx] * tmp[second_idx];	// ���ʿ� ����
					tmp[second_idx] = 0;

					_merge(first_idx, second_idx);
					cout << first_idx << " " << second_idx << endl;
					for (int k = 0; k < tmp.size(); k++){
						cout << tmp[k] << " ";
					}
					cout << endl;
					for (int k = 0; k < num.size(); k++){
						cout << parents[k] << " ";
					}
					cout << endl;
				}
			}
		}
	}
	/*
	cout << "��" << endl;
	for (int i = 0; i < tmp.size(); i++){
		cout << tmp[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < num.size(); i++){
		cout << num[parents[i]] << " ";
	}
	cout << endl;
	*/
	long long answer_tmp = 0;
	for (int i = 0; i < tmp.size(); i++){
		answer_tmp = max(abs(tmp[i]), answer_tmp);
	}
	cout << answer << " " << abs(answer_tmp) << endl;
	answer = max(answer, abs(answer_tmp));
	//cout << "��Ʈ��ŷ ��" << endl;
	cout << answer << endl;
}

void back(int depth){
	if (depth == real_oper.size()){
		// ������ ���� �ϼ�
		memset(check_num, 0, sizeof(check_num));
		solve();
		return;
	}
	for (int i = 0; i < oper.size(); i++){
		if (!check_oper[oper[i]]){	// �ش� ������ �켱������ ������
			check_oper[oper[i]] = 1;
			prime_oper.push_back(oper[i]);	// �켱���� ���� ����ִ�
			back(depth + 1);
			prime_oper.pop_back();
			check_oper[oper[i]] = 0;
		}
	}
}

long long solution(string expression) {
	long long tmp = 0;
	for (int i = 0; i < expression.size(); i++){	// �ִ� 100��
		if (expression[i] >= '0' && expression[i] <= '9'){
			tmp = tmp * 10 + (expression[i] - '0');
		}
		else if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*'){
			num.push_back(tmp);
			tmp = 0;
			oper.push_back(expression[i]);
			real_oper.insert(expression[i]);
		}
		if (i == expression.size() - 1){
			num.push_back(tmp);
		}
	}
	back(0);
	//cout << answer << endl;
	return answer;
}


int main(){
	string exp = "100-200*300-500+20";
	solution(exp);
}