#include <bits/stdc++.h>

using namespace std;



int N,M;

int board[21][21];

//1번째가 윗면 6번째까 바닥면
int dice[7] = {0,0,0,0,0,0,0};

int K;

//동, 서, 북, 남
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

int main(){
    cin >> N >> M;
    int sr, sc;
    cin >> sr >> sc;
    cin >> K;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> board[i][j];
        }
    }
    int curR,curC;
    curR = sr;
    curC = sc;
    for(int i = 0; i<K; i++){
        int cmd;
        cin >> cmd;
        int direction = cmd-1;
        int nr = curR + dr[direction];
        int nc = curC + dc[direction];
        
        if(nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
        curR = nr;
        curC = nc;

        //주사위 굴리기  => 관찰을 통해 알 수 있음
        //동쪽으로 굴렸을 때
        if(direction == 0){
            //4개가 이동 0,2,3,5번 인덱스
            int temp1 = dice[1];
            int temp3 = dice[3];
            int temp4 = dice[4];
            int temp6 = dice[6];
            dice[1] = temp4;
            dice[3] = temp1;
            dice[4] = temp6;
            dice[6] = temp3;
        }else if(direction == 1){
            //4개가 이동 0,2,3,5번 인덱스
            int temp1 = dice[1];
            int temp3 = dice[3];
            int temp4 = dice[4];
            int temp6 = dice[6];
            dice[1] = temp3;
            dice[3] = temp6;
            dice[4] = temp1;
            dice[6] = temp4;
        } //북쪽
        else if(direction == 2){
            //4개가 이동 0,1,4,5번 인덱스
            int temp1 = dice[1];
            int temp2 = dice[2];
            int temp5 = dice[5];
            int temp6 = dice[6];
            dice[1] = temp5;
            dice[2] = temp1;
            dice[5] = temp6;
            dice[6] = temp2;
        }else if(direction == 3){
            //4개가 이동 0,1,4,5번 인덱스
            int temp1 = dice[1];
            int temp2 = dice[2];
            int temp5 = dice[5];
            int temp6 = dice[6];
            dice[1] = temp2;
            dice[2] = temp6;
            dice[5] = temp1;
            dice[6] = temp5;
        }
        
        if(board[nr][nc] == 0){
            board[nr][nc] = dice[6];
        }
        else{
            dice[6] = board[nr][nc];
            board[nr][nc] = 0;
        }
        cout << dice[1] << '\n';
        
        //cout << "\n";

        
    }
    
    return 0;
}