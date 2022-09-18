#include <string>
#include <vector>
#include <iostream>

using namespace std;

//n을 x진법한 문자열 반환 -> 정방향으로 출력
string func(int n, int x){
    string s = "";
    int div = n;
    
    //새로 추가되는 것들이 앞에옴
    while(1){
        if(div >= x){
            int res = div%x;
            if(res == 10){
                s = 'A' + s;
            }else if(res == 11){
                s = 'B' + s;
            }else if(res == 12){
                s = 'C' + s;
            }else if(res == 13){
                s = 'D' + s;
            }else if(res == 14){
                s = 'E' + s;
            }else if(res == 15){
                s = 'F' + s;
            }else{
                s = to_string(res) + s;
            }
            div /= x;
        }
        
        if(div<x){
            if(div == 10){
            s = 'A' + s;
            }else if(div == 11){
                s = 'B' + s;
            }else if(div == 12){
                s = 'C' + s;
            }else if(div == 13){
                s = 'D' + s;
            }else if(div == 14){
                s = 'E' + s;
            }else if(div == 15){
                s = 'F' + s;
            }else{
                s = to_string(div) + s;
            }
            break;
        }
    }
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int temp = 0;
    string x = "";
        
    while(1){
        string s = func(temp++, n); // 해당 숫자를 n진법한 숫자를 문자열로 받음.
        cout << s << '\n';
        //while 문 이므로 temp를 늘려서 차례대로 받음
        x += s; // 기존이 앞에 새로운 것이 뒤에 오도록 추가.
        if(x.size() >= m * t + p) break; // 최소한 문자열이 m * t + p개 이상 있다면 내가 t개를 말할 수 있음. -> while문에서 그만 문자열 받음.
    }
    
    
    
    //지금까지 숫자들 중 내가 말해야하는 것만 고름
    int cnt = 0;
    for(char s : x){
        int turn = (cnt%m); // turn 번째 차례 -> m으로 나눈 나머지므로 나머지가 0이면 첫 번쨰 사람차례다.
        cnt++;
        //p번째 차례 -> 나머지 0,1,2....p-1일 때. p번째 차례.
        if(turn == p-1){
            answer.push_back(s);
            if(answer.size() == t){
                break;
            }
        }else continue; // 내차례 아니면 넘김.
    }
    
    return answer;
}