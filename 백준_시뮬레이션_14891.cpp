#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

string s;
vector<int> cir[4];
int status[4]; // 각각의 cir 의 12시 방향
//(status[num]+2)%8 : 2시방향 , (status[num]+6)%8 : 9시방향
int spin[4];	//1은 시계 -1은 반시계 0은 정지
int k;
int answer;

void check(int num, int dir){	
	// spin할지 말지 num은 target	
	// 한번 act때 spin을 모두 check를 해줘야함 spin하면서 check하면 예상과 다른 결과
	if (num == 0){
		spin[0] = dir;
		if (cir[0][((status[num] + 2) % 8)] != cir[1][((status[num + 1] + 6) % 8)]){	// 0 == 1
			spin[1] = -dir;
			if (cir[1][((status[num + 1] + 2) % 8)] != cir[2][((status[num + 2] + 6) % 8)] && spin[1]){
				spin[2] = dir;
				if (cir[2][((status[num + 2] + 2) % 8)] != cir[3][((status[num + 3] + 6) % 8)] && spin[2]){
					spin[3] = -dir;
				}
			}
		}
	}
	if (num == 1){
		spin[1] = dir;
		if (cir[1][((status[1] + 2) % 8)] != cir[2][((status[2] + 6) % 8)] && spin[1]){
			spin[2] = -dir;
			if (cir[2][((status[2] + 2) % 8)] != cir[3][((status[3] + 6) % 8)] && spin[2]){
				spin[3] = dir;
			}
		}
		if (cir[0][((status[0] + 2) % 8)] != cir[1][((status[1] + 6) % 8)] && spin[1]){
			spin[0] = -dir;
		}
	}
	if (num == 2){
		spin[2] = dir;
		if (cir[2][((status[2] + 2) % 8)] != cir[3][((status[3] + 6) % 8)] && spin[2]){
			spin[3] = -dir;
		}
		if (cir[1][((status[1] + 2) % 8)] != cir[2][((status[2] + 6) % 8)] && spin[2]){
			spin[1] = -dir;
			if (cir[0][((status[0] + 2) % 8)] != cir[1][((status[1] + 6) % 8)] && spin[1]){
				spin[0] = dir;
			}
		}
	}
	if (num == 3){
		spin[3] = dir;
		if (cir[2][((status[2] + 2) % 8)] != cir[3][((status[3] + 6) % 8)] && spin[3]){
			spin[2] = -dir;
			if (cir[1][((status[1] + 2) % 8)] != cir[2][((status[2] + 6) % 8)] && spin[2]){
				spin[1] = dir;
				if (cir[0][((status[0] + 2) % 8)] != cir[1][((status[1] + 6) % 8)]&&spin[1]){
					spin[0] = -dir;
				}
			}
		}
	}
}

void act(){
	for (int i = 0; i < 4; i++){
		if (spin[i] == -1){
			status[i] = (status[i] + 1) % 8;
		}
		if (spin[i] == 1){
			status[i] = (status[i] + 7) % 8;
		}
	}
	//for (int i = 0; i < 4; i++){
	//	cout << status[i] << " ";
	//}
	//cout << endl;
}

int main(){
	for (int i = 0; i < 4; i++){
		cin >> s;
		for (int j = 0; j < s.size(); j++){
			cir[i].push_back(s[j]-'0');
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++){
		int num, dir;
		cin >> num >> dir;
		memset(spin, 0, sizeof(spin));
		check(num-1,dir);
		act();
		//함수
	}
	for (int i = 0; i < 4; i++){
		answer += (cir[i][status[i]] * (pow(2, i)));
	}
	cout << answer << endl;
}