#include<iostream>
#include<queue>

#define X first
#define Y second

using namespace std;

int visit[1002][1002];
int box[1002][1002];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;

    int day = 0;
    cin >> m >> n;
    bool check = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
            visit[i][j] = -1;


            //익은 토마토의 위치파악 -> BFS가 시작할 위치
            if (box[i][j] == 1) {
                Q.push({i, j});
                visit[i][j] = 0;
            }
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visit[nx][ny] >= 0 || box[nx][ny] == -1)
                continue;
            visit[nx][ny] = visit[cur.X][cur.Y] + 1;
            day = visit[nx][ny];
            Q.push({nx, ny});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 0 && visit[i][j] == -1){
                cout << -1;
                check = false;
                break;
            }
        }
        if (!check)
            break;
    }


    if (check)
        cout << day;

}