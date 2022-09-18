#include <bits/stdc++.h>

using namespace std;

void Balanced(string str, int* pos){
    int open = 0;
    int close = 0;
    
    for(int i = 0; i<str.length(); i++){
        if(str[i] == '('){
            open++;
        }
        else {
            close++;
        }
        
        
        if(open == close){
            *pos = i + 1;
            return;
        }
    }
}

bool IsCorrect(string str){
    stack<char> stk;
    for(char c : str){
        if(c == '(') {
            stk.push(c);
        }
        else{
            if(stk.empty())return false;
            stk.pop();
        }
    }
    if(!stk.empty())return false;
    
    return true;
    
}


string solution(string p) {
    if(p.empty()) return p;
    
    int pos;
    Balanced(p, &pos);
    
    string u = p.substr(0,pos);
    string v = p.substr(pos);
    
    if(IsCorrect(u)){
        return u + solution(v);
    }
    
    string answer = "(" + solution(v) + ")";
    for(int i = 1; i<u.length()-1; i++){
        if(u[i] == '('){
            answer += ")";
        }
        else {
            answer += "(";
        }
    }
    

    return answer;
}