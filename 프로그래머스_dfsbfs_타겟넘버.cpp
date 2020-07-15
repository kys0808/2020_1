#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int check[21];
int solution(vector<int> numbers, int target) {
	int answer = 0;
	int max = 0;
	for (int i = 0; i < numbers.size(); i++){
		max += numbers[i];
	}
	if (max != target){
		int check_size = 1;// -�� ����
		while (check_size != numbers.size()){
			int status = check_size-1;	// ������
			int tmp_max = max;
			for (int i = 0; i < check_size; i++){	// ���� �غ�
				check[i] = 1;
				tmp_max = tmp_max - 2 * numbers[i];
			}
			while (status != numbers.size()){	// index ������
				if (!check[status]){	// �湮 ���ߴٸ�
					check[status] = 1;
					tmp_max = tmp_max - 2 * numbers[status];
					if (tmp_max == target){
						check_size++;
						answer++;
						break;
					}
					else{
						status++;
					}
				}
			}
			for (int i = 0; i < 21; i++){
				check[i] = 0;
			}
		}
		return answer;
	}
	else{
		return 1;
	}
}

int main(){
	vector<int> numbers = { 1, 1, 1, 1, 1 };
	int target = 3;
	solution(numbers, target);
}