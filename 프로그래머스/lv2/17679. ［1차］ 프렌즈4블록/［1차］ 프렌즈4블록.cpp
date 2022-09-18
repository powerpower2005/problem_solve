#include <string>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    //m = 행, row
    //n = 열, col
    auto temp = board;
    
    vector<queue<char>> queue(n);  //n개의 열을 큐로 만듦  
    
    //board에서 4개쌍을 찾아야함
    while(1){
        //cout << count << '\n';
        bool any = false; //4개 쌍이 하나라도 있으면 
        
        
        auto copy = temp;    //copy가 before 상태를 저장하고 있는 보드임
        
        for(int i = 0 ; i<m-1; i++){
            for(int j = 0; j<n-1; j++){
                auto c = copy[i][j];
                if(c == 'x')continue; //"x"는 블럭이 아니라 빈칸임
                if(copy[i][j+1] == c && copy[i+1][j] == c && copy[i+1][j+1] == c ){
                    temp[i][j] = temp[i+1][j] = temp[i][j+1] = temp[i+1][j+1] = 'x'; //소문자 x (지워져야하는 칸)
                    any = true;
                }
            }
        }


        //지울 게 없으면 종료 => 지운 블럭 계산후 종료
        if(!any){
            for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                    if(temp[i][j] == 'x')answer++;
                }
            }
            break;
        }
        
        
        //board에서 지움
        for(int i = m-1; i>=0; i--){
            for(int j = 0; j<n; j++){
                auto now = temp[i][j];
                if(now != 'x'){
                    queue[j].push(now);
                }
            }
        }
        
        
        //큐의 높이가 m이 안되는 칸에는 x를 넣어줌
        for(int i = 0; i<n; i++){
            while(queue[i].size() < m){
                queue[i].push('x');
            }
        }


        //지운 뒤의 board 업데이트
        for(int i = m-1; i>=0; i--){
            for(int j = 0; j<n; j++){
                if(queue[j].empty())continue;
                auto now = queue[j].front();
                temp[i][j] = now;
                queue[j].pop();
            }
        }
        

    }
    
    return answer;
}