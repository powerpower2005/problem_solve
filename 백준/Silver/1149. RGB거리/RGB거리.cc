#include<iostream>
#include<algorithm>

using namespace std;
int N;
int color[1001][3];
int dp[1001][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 3; j++){
            cin >> color[i][j]; // 모든 cost 집어넣음 //0,1,2 = R,G,B
        }
    }
    
    
    //초항 1번집의 삼색
    dp[1][0] = color[1][0];
    dp[1][1] = color[1][1];
    dp[1][2] = color[1][2];
    for(int i = 2; i<=N; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + color[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + color[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + color[i][2];
    }
    
    int m = dp[N][0];
    for(int i = 1; i<=2; i++){
        m = min(m, dp[N][i]);
    }
    
    cout << m << '\n';
    
    
}