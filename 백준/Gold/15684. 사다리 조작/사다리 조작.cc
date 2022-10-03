#include <bits/stdc++.h>


#define RIGHT 1
#define LEFT 2
#define INF 987654321

using namespace std;

int N,M,H;

int ladder[30][10]; //사다리


bool check(){
    for(int i = 0; i<N; i++){
        int c = i; //열 위치
        int r = 0;
        while(r != H){
            if(ladder[r][c] == RIGHT){
                c++;
            }else if(ladder[r][c] == LEFT){
                c--;
            }
            r++;
        }
        //하나라도 같지 않으면 false
        //마지막에 도착한 위치와 출발한 위치가 같지 않다면
        if(c != i){
            return false;
        }
    }
    return true;
}

//pos : 사다리를 추가시킬 위치, cnt : 추가시킨 사다리 개수
int solve(int pos, int cnt){
    
    int ret = INF;
    //pos : 0 ~ (H * N) -1
    if(pos >= H * N || cnt == 3){
        
       //사다리를 놓은 결과가 조건에 부합하는지 확인
        if(check()){
            return cnt;
        }else{
            return INF;
        }
    }
    //해당 위치에 사다리 놓기
    int r = pos / N;
    int c = pos % N;
    if(ladder[r][c] == 0 && ladder[r][c+1] == 0 && c < N-1){
        ladder[r][c] = RIGHT;
        ladder[r][c+1] = LEFT;
        ret = min(ret, solve(pos+2, cnt+1)); //어차피 다음 칸은 RIGHT임
        ladder[r][c] = 0;
        ladder[r][c+1] = 0;
    }
    //해당 위치에 놓지 않기
    ret = min(ret, solve(pos+1, cnt));
    
    return ret;
}

int main(){
    cin >> N >> M >> H;
    for(int i = 0; i<M; i++){
        int a,b;
        cin >> a >> b;
        ladder[a-1][b-1] = RIGHT;
        ladder[a-1][b] = LEFT;
    }
    
    int ans = solve(0,0);
    
    
    if(ans > 3 ){
        cout << "-1" << '\n';
    }else{
        cout << ans << '\n';
    }
    

    
    return 0;
}