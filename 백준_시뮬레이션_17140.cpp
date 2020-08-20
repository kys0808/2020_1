#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int r, c, k;
int arr[101][101];
int check[101];
int row_num = 3;	// �� ��,�� �߿��� ���� �� ���� ���� �����
int col_num = 3;
vector<pair<int,int>> tmp_col[101];	// �� �ະ�� �ӽ� �����
vector<pair<int,int>> tmp_row[101];

int check_time = 0;

bool cmp(pair<int,int> &a , pair<int,int> &b){
	if (a.second < b.second){
		return true;
	}
	else if (a.second == b.second){
		if (a.first < b.first){
			return true;
		}
		else
			return false;
	}
	else{
		return false;
	}
}

void act_r(){
	for (int i = 0; i < 101; i++){
		if (!tmp_col[i].empty())
			tmp_col[i].clear();
		if (!tmp_row[i].empty())
			tmp_row[i].clear();
	}
	for (int i = 0; i < row_num; i++){
		memset(check, 0, sizeof(check));
		for (int j = 0; j < col_num; j++){
			if (arr[i][j]){
				check[arr[i][j]]++;	// �ش� ��ȣ�� ���� ����
			}
		}
		// �ϳ��� �� �����ݾ�
		for (int j = 0; j < 101; j++){
			if (check[j]){// ���� ������
				tmp_row[i].push_back({ j, check[j] });	// ���ڿ� ���� push
			}
		}
	}
	// �� �ึ�� ����, ���� �ľ������� ����
	for (int i = 0; i < 101; i++){
		if (!tmp_row[i].empty()){
			sort(tmp_row[i].begin(), tmp_row[i].end(), cmp);
		}
	}


	// ���� �������� �迭 �����ؾ���
	vector<int> tmp[101];
	for (int i = 0; i < row_num; i++){
		if (!tmp_row[i].empty()){
			for (int j = 0; j < tmp_row[i].size(); j++){
				if (tmp_row[i][j].first != 0 && tmp_row[i][j].second != 0){
					tmp[i].push_back(tmp_row[i][j].first);
					tmp[i].push_back(tmp_row[i][j].second);
				}
			}
		}
	}
	// ũ�� ����
	for (int i = 0; i < row_num; i++){
		int size = tmp[i].size();
		col_num = max(col_num, size);
	}


	// �迭 ����
	for (int i = 0; i < row_num; i++){
		for (int j = 0; j < col_num; j++){
			if (j<tmp[i].size()){	// ������ ���
				arr[i][j] = tmp[i][j];
			}
			else{
				arr[i][j] = 0;
			}
		}
	}
}

void act_c(){
	for (int i = 0; i < 101; i++){
		if (!tmp_col[i].empty())
			tmp_col[i].clear();
		if (!tmp_row[i].empty())
			tmp_row[i].clear();
	}
	for (int i = 0; i < col_num; i++){
		memset(check, 0, sizeof(check));
		for (int j = 0; j < row_num; j++){
			if (arr[j][i]){
				check[arr[j][i]]++;	// �ش� ��ȣ�� ���� ����
			}
		}
		// �ϳ��� �� �����ݾ�
		for (int j = 0; j < 101; j++){
			if (check[j]){// ���� ������
				tmp_col[i].push_back({ j, check[j] });	// ���ڿ� ���� push
			}
		}
	}
	// �� �ึ�� ����, ���� �ľ������� ����
	for (int i = 0; i < col_num; i++){
		if (!tmp_col[i].empty()){
			sort(tmp_col[i].begin(), tmp_col[i].end(), cmp);
		}
	}


	// ���� �������� �迭 �����ؾ���
	vector<int> tmp[101];
	for (int i = 0; i < col_num; i++){
		if (!tmp_col[i].empty()){
			for (int j = 0; j < tmp_col[i].size(); j++){
				if (tmp_col[i][j].first != 0 && tmp_col[i][j].second != 0){
					tmp[i].push_back(tmp_col[i][j].first);
					tmp[i].push_back(tmp_col[i][j].second);
				}
			}
		}
	}
	// ũ�� ����
	for (int i = 0; i < col_num; i++){
		int size = tmp[i].size();
		row_num = max(row_num, size);
	}

	// �迭 ����
	for (int i = 0; i < col_num; i++){
		for (int j = 0; j < row_num; j++){
			if (j<tmp[i].size()){	// ������ ���
				arr[j][i] = tmp[i][j];
			}
			else{
				arr[j][i] = 0;
			}
		}
	}
}

int main(){
	cin >> r >> c >> k;	 // arr[r][c]�� k�� �ִ�
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cin >> arr[i][j];
		}
	}
	while (1){
		if (arr[r-1][c-1] == k){
			cout << check_time << endl;
			return 0 ;
		}
		if (check_time > 100){
			cout << -1;
			return 0;
		}
		else{
			check_time++;
			if (row_num >= col_num){
				act_r();
				continue;
			}
			if (row_num < col_num){
				act_c();
				continue;
			}
		}
	}
}