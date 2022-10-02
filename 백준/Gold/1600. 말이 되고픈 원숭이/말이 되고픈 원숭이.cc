#include <bits/stdc++.h>

using namespace std;

int W,H,K;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int dhr[8] = {-1,-1,1,1,-2,-2,2,2};
int dhc[8] = {2,-2,2,-2,1,-1,1,-1};

int board[201][201];
int visited[201][201][30];

struct Node{
    int r;
    int c;
    int k;
};

int main(){

    int ans = -1;
    cin >> K >> W >> H;
    int r,c;
    r = H;
    c = W;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin >> board[i][j];
        }
    }
    //-1로 방문배열 초기화
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            for(int k = 0; k<=K; k++){
                visited[i][j][k] = -1;
            }
        }
    }
    
    queue<Node> q;
    Node n;
    n.r = 0;
    n.c = 0;
    n.k = 0;
    visited[0][0][0] = 0;
    q.push(n);
    
    while(!q.empty()){
        auto cur = q.front();
        //cout << cur.r << " " << cur.c << " K: " << cur.k << '\n';
        //cout << "val : " << visited[cur.r][cur.c][cur.k] << '\n';
        q.pop();
        if(cur.r == r-1 && cur.c == c-1){
            ans = visited[cur.r][cur.c][cur.k];
            break;
        }
        
        
        //K번만큼 뛰어넘기 가능
        if(cur.k < K){
            for(int dir = 0; dir<8; dir++){
                int nr = cur.r + dhr[dir];
                int nc = cur.c + dhc[dir];
                
                if(nr<0 || nc < 0 || nr >=H || nc >= W)continue;
                if(board[nr][nc] == 1)continue;
                Node next;
                next.r = nr;
                next.c = nc;
                next.k = cur.k + 1;
                if(visited[nr][nc][next.k] > -1)continue;
                if(visited[nr][nc][next.k] < visited[nr][nc][cur.k] + 1 && visited[nr][nc][next.k] != -1)continue; //더 빨리 도착했다면
                visited[nr][nc][next.k] = visited[cur.r][cur.c][cur.k] + 1;
                q.push(next);
            }
        }
        
        //인접
        for(int dir = 0; dir<4; dir++){
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];
            if(nr<0 || nc < 0 || nr >=H || nc >= W)continue;
            if(board[nr][nc] == 1)continue;
            Node next;
            next.r = nr;
            next.c = nc;
            next.k = cur.k;
            if(visited[nr][nc][next.k] > -1)continue;
            if(visited[nr][nc][next.k] < visited[nr][nc][cur.k] + 1 && visited[nr][nc][next.k] != -1)continue; //더 빨리 도착했다면
            visited[nr][nc][next.k] = visited[cur.r][cur.c][cur.k] + 1;
            q.push(next);
        }
        
        
    }
    
    cout << ans << '\n';
    return 0;
}