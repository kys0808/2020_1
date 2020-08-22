#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> tmp;	// ���� ���
	for (int i = 0; i < moves.size(); i++){
		int num = moves[i] - 1;
		for (int j = 0; j < board.size(); j++){	// ���� �̱���
			if (board[j][num]){	// �ش� �ڸ��� ����������?
				if (!tmp.empty()){	// ���� �ٱ��Ͽ� ����������
					if (board[j][num] == tmp[tmp.size() - 1]){	// �������� ���ؼ� ������
						answer += 2;
						board[j][num] = 0;
						tmp.pop_back();
						break;
					}
					else{
						tmp.push_back(board[j][num]);
						board[j][num] = 0;
						break;
					}
				}
				else{
					tmp.push_back(board[j][num]);
					board[j][num] = 0;
					break;
				}

			}
		}
	}
	return answer;
}