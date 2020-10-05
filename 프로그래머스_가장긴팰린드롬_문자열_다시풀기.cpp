#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;


int solution(string s)
{
	int len = s.size();
	while (len >= 2){
		for (int i = 0; len-1+i < s.size(); i++){
			int left = i;
			int right = len - 1 + i;
			bool keep = true;
			while (left < right){
				if (s[left] != s[right]){
					keep = false;
					break;
				}
				left++;
				right--;
			}
			if (keep == true){
				return len;
			}
		}
		len--;
	}
	return 1;

}
int main(){
	string s = "abcdefg";
	solution(s);
}