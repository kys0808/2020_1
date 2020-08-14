#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int n, l;
int arr[101][101];
int answer;
int p1[101][101];	// Ææ½º ¼³Ä¡ °¡·Î
int p2[101][101];
int main(){
	cin >> n >> l;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	// °¡·Î
	for (int i = 0; i < n; i++){
		int pense_check = true;
		for (int j = 0; j < n - 1; j++){
			int cnt = 0;
			if (arr[i][j] < arr[i][j + 1] && (arr[i][j+1] - arr[i][j]) == 1 ){
				for (int k = 0; k < l; k++){
					int check_idx = j - k;
					if (check_idx >= 0){
						if (arr[i][j] != arr[i][check_idx] || p1[i][check_idx]){
							pense_check = false;
							break;
						}
						else{
							cnt++;
						}
					}
				}
				if (cnt == l){
					for (int k = 0; k < l; k++){
						if (!p1[i][j - k])
							p1[i][j - k] = 1;	// Ææ½º ¼³Ä¡
					}
				}
			}
			pense_check = true;
			cnt = 0;
			if (arr[i][j] > arr[i][j + 1] || (arr[i][j] - arr[i][j+1]) == 1){
				for (int k = 0; k < l; k++){
					int check_idx = j + 1 + k;
					if (check_idx < n){
						if (arr[i][j + 1] != arr[i][check_idx] || p1[i][check_idx]){
							pense_check = false;
							break;
						}
						else{
							cnt++;
						}
					}
				}
				if (cnt == l){
					for (int k = 0; k < l; k++){
						if (!p1[i][j + 1 + k])
							p1[i][j + 1 + k] = 2;	// Ææ½º ¼³Ä¡
					}
				}
			}
		}
	}

	// ¼¼·Î
	for (int i = 0; i < n; i++){
		int pense_check = true;
		for (int j = 0; j < n - 1; j++){
			int cnt = 0;
			if (arr[j][i] < arr[j+1][i] && (arr[j+1][i] - arr[j][i]) == 1){
				for (int k = 0; k < l; k++){
					int check_idx = j - k;
					if (check_idx >= 0){
						if (arr[j][i] != arr[check_idx][i] || p2[check_idx][i]){
							pense_check = false;
							break;
						}
						else{
							cnt++;
						}
					}
				}
				if (cnt == l){
					for (int k = 0; k < l; k++){
						if (!p2[j-k][i])
							p2[j-k][i] = 1;	// Ææ½º ¼³Ä¡
					}
				}
			}
			cnt = 0;
			pense_check = true;
			if (arr[j][i] > arr[j+1][i] || (arr[j][i] - arr[j+1][i]) == 1){
				for (int k = 0; k < l; k++){
					int check_idx = j + 1 + k;
					if (check_idx < n){
						if (arr[j+1][i] != arr[check_idx][i] || p2[check_idx][i]){
							pense_check = false;
							break;
						}
						else{
							cnt++;
						}
					}
				}
				if (cnt == l){
					for (int k = 0; k < l; k++){
						if (!p2[j+1+k][i])
							p2[j + 1 + k][i] = 2;	// Ææ½º ¼³Ä¡
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++){
		bool plus = true;
		for (int j = 0; j < n - 1; j++){
			if (arr[i][j] == arr[i][j + 1]){
				continue;
			}
			else if (arr[i][j] < arr[i][j + 1] && ((arr[i][j+1] - arr[i][j]) == 1)){
				if (p1[i][j] == 1){
					continue;
				}
				else{
					plus = false;
					break;
				}
			}
			else if (arr[i][j] > arr[i][j + 1] && ((arr[i][j] - arr[i][j+1]) == 1)){
				if (p1[i][j+1] == 2){
					continue;	
				}
				else{
					plus = false;
					break;
				}
			}
			else{
				plus = false;
			}
		}
		if (plus == true){
			answer++;
		}
	}

	for (int i = 0; i < n; i++){
		bool plus = true;
		for (int j = 0; j < n - 1; j++){
			if (arr[j][i] == arr[j+1][i]){
				continue;
			}
			else if (arr[j][i] < arr[j+1][i] && ((arr[j+1][i] - arr[j][i]) == 1)){
				if (p2[j][i] == 1){
					continue;
				}
				else{
					plus = false;
					break;
				}
			}
			else if (arr[j][i] > arr[j+1][i] && ((arr[j][i] - arr[j+1][i]) == 1)){
				if (p2[j+1][i] == 2){
					continue;
				}
				else{
					plus = false;
					break;
				}
			}
			else{
				plus = false;
			}
		}
		if (plus == true){
			answer++;
		}
	}

	cout << answer << endl;
}