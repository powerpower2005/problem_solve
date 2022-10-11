#include <bits/stdc++.h>

using namespace std;

#define MAX 21
#define EMPTY -2
#define RAINBOW 0
#define BLACK -1

int board[MAX][MAX];
int temp[MAX][MAX];
int N,M;

set<pair<int,int>> rainbows;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};



bool visited[MAX][MAX];
int MM = -1;  //블록의 개수는 2보다 크거나 같아야함
int RR = -1; //무지개 블록의 개수
int COL = -1;
int ROW = -1;

bool compare(int block, int rainbow, int col, int row){
    if(block < 2)return false;
    if(MM == block){
        if(RR == rainbow){
            if(COL == col){
                return row > ROW;
            }
            return col > COL;
        }
        return rainbow > RR;
    }
    return block > MM;
}


void DFS(int r, int c, int &cnt, vector<pair<int,int>> &block, int color, int &rainbow){
    visited[r][c] = true;
    cnt++;
    if(board[r][c] == RAINBOW){
        rainbow++;
        rainbows.insert({r,c});
    }
    block.push_back({r,c});
    for(int dir = 0; dir<4; dir++){
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
        if(visited[nr][nc] == true)continue;
        if(board[nr][nc] == BLACK)continue;
        if(board[nr][nc] == EMPTY)continue;
        if(board[nr][nc] == color || board[nr][nc] == 0 ){
            DFS(nr,nc, cnt, block, color, rainbow);
        }
    }
}


int main(){
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
        }
    }
    int score = 0;
    while(1){
        //1.크기가 가장 큰 블록 그룹찾기
        //visited 초기화
        memset(visited, false, sizeof(visited));
        vector<pair<int,int>> candi;
        rainbows.clear();
        MM = -1;  //블록의 개수는 2보다 크거나 같아야함
        RR = -1;  //무지개 블록의 개수
        COL = -1;
        ROW = -1;

        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(board[i][j] == EMPTY)continue;
                if(board[i][j] == BLACK)continue;
                if(board[i][j] == RAINBOW){
                    rainbows.insert({i,j});
                    continue;
                } //무지개는 따로 담아놓음
                if(visited[i][j] == true)continue;
                int count = 0;
                int rb = 0;
                int coco = i; //기준 블럭
                int roro = j; //기준 블럭
                vector<pair<int,int>> comp;

                DFS(i,j,count, comp, board[i][j], rb);
                
                
                bool isUpdate = compare(count, rb, coco, roro);
                if(isUpdate){
                    MM = count;
                    RR = rb;
                    COL = coco;
                    ROW = roro;
                    candi = comp;
                }
                
                //무지개 블럭은 여러번 쓰이므로 방문 재활용
                for(auto c : rainbows){
                    visited[c.first][c.second] = false;
                }
            }
        }
        

        //2. 점수 추가 후 제거
        int B = candi.size();
        if(B<2)break;
        score += B*B;
        for(auto c : candi){
            board[c.first][c.second] = EMPTY;
        }


        //3. 중력 적용  => 마지막행부터 0행으로 역순으로 한 열에 대해서만
        for(int i = 0; i<N; i++){
            //맨 밑에있는 칸은 옮기지 않음
            for(int j = N-2; j>=0; j--){
                if(board[j][i] == EMPTY)continue; //빈칸을 옮기진 않음
                if(board[j][i] == -1)continue; //검정 블럭도 옮기지 않음
                auto cur = board[j][i];//해당 j보다 밑에있는 칸에 대해서 조사후 내릴지 결정
                
                for(int k = j+1; k<N; k++){
                    //검은색이거나 비어있지 않으면 못내려감
                    if(board[k][i] == EMPTY){
                        //내려감 => 이전칸을 비우고 아래칸으로 내려감
                        board[k-1][i] = EMPTY;
                        board[k][i] = cur;
                    }else{
                        break;
                    }
                }
            }
        }


        
        //4. 반시계 90도 회전 (0,0) => (N-1,0)  &&  (0,1) => (N-2, 0);   
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                temp[N-j-1][i] = board[i][j];
            }
        }
        
        //2차원 배열 복사는 조금 다르게 한다.
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                board[i][j] = temp[i][j];
            }
        }


        //5. 중력 적용 => 마지막행부터 0행으로 역순으로 한 열에 대해서만
        for(int i = 0; i<N; i++){
            //맨 밑에있는 칸은 옮기지 않음
            for(int j = N-2; j>=0; j--){
                if(board[j][i] == EMPTY)continue; //빈칸을 옮기진 않음
                if(board[j][i] == -1)continue; //검정 블럭도 옮기지 않음
                auto cur = board[j][i];//해당 j보다 밑에있는 칸에 대해서 조사후 내릴지 결정
                
                for(int k = j+1; k<N; k++){
                    //검은색이거나 비어있지 않으면 못내려감
                    if(board[k][i] == EMPTY){
                        //내려감 => 이전칸을 비우고 아래칸으로 내려감
                        board[k-1][i] = EMPTY;
                        board[k][i] = cur;
                    }else{
                        break;
                    }
                }
            }
        }
    }
    
    cout << score << '\n';
    
    
    return 0;
}