#include <bits/stdc++.h>


using namespace std;

int board[101][101];
int visited[101][101];

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

bool check(int r, int c){
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(board[i][j] == 1) return false;
        }
    }
    return true;
}

int main(){
    int r,c;
    cin >> r >> c;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin >> board[i][j];
        }
    }
    
    int count = 0;
    bool isDone = false;
    
    while(1){
        
        //치즈가 남아있으면 진행
        isDone = check(r,c);
        if(isDone)break;
        memset(visited, 0, sizeof(visited));
        
        queue<pair<int,int>> q;
        //모눈종이의 가장자리 4군데 q에 추가
        q.push({0,0});
        q.push({r-1,0});
        q.push({r-1,c-1});
        q.push({0,c-1});
        
        visited[0][0] = 1;
        visited[r-1][0] = 1;
        visited[r-1][c-1] = 1;
        visited[0][c-1] = 1;
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            //cout << cur.first << " " << cur.second << '\n';
            for(int dir = 0; dir<4; dir++){
                int nr = cur.first + dr[dir];
                int nc = cur.second + dc[dir];
                if(nr<0 || nc < 0 || nr >= r || nc >= c)continue;
                //공기끼리 방문
                if(visited[nr][nc] == 0){
                    if(board[nr][nc] == 0){
                        visited[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
                //공기의 치즈 방문
                if(visited[nr][nc] > 0 || board[nr][nc] == 1){
                    visited[nr][nc] += 1;
                }
            }
        }
        
        //변 2개 접하는 것들 제거
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(visited[i][j] >= 2){
                    board[i][j] = 0;
                }
            }
        }

        count++;
    }
    
    cout << count << '\n';

    return 0;
}