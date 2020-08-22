#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> tmp;	// 인형 담기
	for (int i = 0; i < moves.size(); i++){
		int num = moves[i] - 1;
		for (int j = 0; j < board.size(); j++){	// 인형 뽑기판
			if (board[j][num]){	// 해당 자리에 인형있으면?
				if (!tmp.empty()){	// 뽑은 바구니에 인형있으면
					if (board[j][num] == tmp[tmp.size() - 1]){	// 마지막과 비교해서 같으면
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