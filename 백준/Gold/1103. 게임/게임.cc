#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

const int MAX = 51;

int r, c;

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int ans = 0; //최대 동전 움직인 횟수.
bool chkInf = false;

int board[MAX][MAX];
int visited[MAX][MAX];
//int finished[MAX][MAX];
int dp[MAX][MAX];


//cr,cc는 위치를 위함 cnt는 동전 움직인 횟수를 위함.
void DFS(int cr, int cc, int cnt) {
    visited[cr][cc] = 1;//방문처리
    int val = board[cr][cc];
    ans = max(ans, cnt);
    dp[cr][cc] = cnt;//해당 방문까지 움직이는 횟수 저장.(DFS의 중복 계산 방지)
    
    for (int dir = 0; dir < 4; dir++){
        int nr = cr + (dr[dir] * val);
        int nc = cc + (dc[dir] * val);
        //범위 체크(밖으로 나감)
        if (nr < 1 || nr > r || nc < 1 || nc > c)continue;
        //구멍 체크(구멍에 빠져서끝남)
        if (board[nr][nc] == 0)continue;
        //방문한 위치가 DP에 Memoization이 되어있으면서 && 현재 DFS가 진행된 시간보다 크다면
        // cnt >= dp[nr][nc]라면 해당 버틴 시간이 dp를 갱신하면서 다시 만들어질 것이다.
        //즉, DP에는 항상 최댓값이 저장된다. cnt < dp[nr][nc]의 뜻이 바로 DP이다.
        if(dp[nr][nc] > 0 && cnt < dp[nr][nc])continue;

        
        //방문하지 않았다면 바로 DFS 시작
        if (visited[nr][nc] == -1) {
            DFS(nr, nc, cnt+1);
        }
        //방문을 한 노드지만 아직 DFS가 끝나지 않을 때 방문했다면 Cycle
        else if (visited[nr][nc] != -1) {
            chkInf = true;
            return;
        }
    }
    //DFS 호출이 끝났다면 -> 백트래킹과 같음
    visited[cr][cc] = -1;
}

int main() {
    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        string s;
        cin >> s;
        memset(visited, -1, sizeof(visited)); // visited -1로 초기화
        for (int j = 1; j <= c; j++) {
            if (s[j-1] == 'H') { board[i][j] = 0; continue; }  //0이 구멍임  + string도 index 0부터시작함
            board[i][j] = s[j-1] - '0';
        }
    }

    DFS(1, 1, 1); //처음 위치와 처음엔 동전을 0번 움직였지만 (마지막에 1번 움직여서 끝나므로 1부터 시작)

    if (chkInf) {
        cout << "-1";
        return 0;
    }
    //DFS를 최대한까지 돌렸다면 ans가 답이 된다.
    cout << ans; //마지막은 한 번 움직여서 끝나므로 +1을 더해줘서 끝냄.(위에서 DFS(1,1,1)로 시작하는 이유)

    return 0;
}