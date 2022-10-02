#include <bits/stdc++.h>

using namespace std;

int N;

int board[1001];

int main(){
    cin >> N;
    int maxHeight = 0;
    int maxPos = 0;
    int startPos = 1002;
    int endPos = 0;
    for(int i = 0; i<N; i++){
        int pos, height;
        cin >> pos >> height;
        board[pos] = height;
        if(height > maxHeight){
            maxPos = pos;
            maxHeight = height;
        }
        if(pos < startPos){
            startPos = pos;
        }
        if(pos > endPos){
            endPos = pos;
        }
    }
    
    
    int answer = 0;
    
    stack<int> stk;
    
    //최댓값 포함
    for(int i = startPos; i<=maxPos; i++){
        if(stk.empty()){
            stk.push(board[i]);
        }else if(stk.top() < board[i]){
            stk.push(board[i]);
        }
        answer += stk.top();
           
    }
                 
    while(!stk.empty())stk.pop();
    
    //최댓값제외
    for(int i = endPos; i> maxPos; i--){
        if(stk.empty()){
            stk.push(board[i]);
        }else if(stk.top() < board[i]){
            stk.push(board[i]);
        }
        answer += stk.top();
    }
    
    cout << answer << '\n';
    
    
    return 0;
}