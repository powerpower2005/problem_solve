#include <bits/stdc++.h>

using namespace std;



int main(){
    string main;
    string bomb;
    
    string answer = "";
    cin >> main >>bomb;
    int size = main.size();
    int sizeb = bomb.size();
    for(int i = 0; i<size; i++){
        answer += main[i];
        //폭탄 글자의 마지막이라면 앞에 문자열을 조사해봐야함.
        if(main[i] == bomb.back()){
            //조사할 문자열이 더 길어야 폭탄이 있을수도 있음
            if(answer.size() >= sizeb){
                bool isBomb = true;
                //맨뒤에서부터 폭탄 문자열 비교
                int sizea = answer.size();
                for(int j = sizeb-1; j>=0; j--){
                    if(bomb[j] != answer[sizea - sizeb + j]){
                        isBomb = false;
                        break;
                    }
                }
                
                //폭탄이면 뒤에서부터 제거
                if(isBomb){
                    for(int k = 0; k<sizeb; k++){
                        answer.pop_back();
                    }
                }
                
            }
        }
    }
    if(answer.size() > 0){
        cout << answer << '\n';
    }else{
        cout << "FRULA\n";
    }
    return 0;
}