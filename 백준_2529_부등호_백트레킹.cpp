#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<char> oper;
vector<string> answer;
string tmp_ans;
int check[10];

string max_ans;
string min_ans;

int n;

void back(int depth){
    if(depth == n+1){
        answer.push_back(tmp_ans);
        return;
    }
    for(int i=0;i<10;i++){
        if(check[i] == 0){
            if(depth == 0){
                check[i] = 1;
                tmp_ans.push_back(i+'0');
                back(depth+1);
                tmp_ans.pop_back();
                check[i] =0;
            }
            else{
                if(oper[depth-1] == '<'){
                    if(tmp_ans[depth-1] < i+'0'){
                        check[i] = 1;
                        tmp_ans.push_back(i+'0');
                        back(depth+1);
                        tmp_ans.pop_back();
                        check[i]=0;
                    }
                }
                else if(oper[depth-1] == '>'){
                    if(tmp_ans[depth-1] > i+'0'){
                        check[i] = 1;
                        tmp_ans.push_back(i+'0');
                        back(depth+1);
                        tmp_ans.pop_back();
                        check[i] =0;
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>> n;
    for(int i=0;i<n;i++){
        char tmp;
        cin >>tmp;
        oper.push_back(tmp);
    }
    back(0);
    sort(answer.begin(),answer.end());
    cout <<answer[answer.size()-1]<<endl;
    cout <<answer[0]<<endl;
}