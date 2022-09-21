#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <bitset> //bit 연산을 위함

#define SIZE 50

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//key를 비트로 표현하자. 000000 -> 6비트로 표현가능 6가지 상태 저장가능

int row, col;

char map[SIZE][SIZE];
int visited[SIZE][SIZE][64]; //64는 2^6 이다. 6가지 상태에 따른 차원

typedef struct Position {
    int x;
    int y;
    bitset<6> keys; // 6개 비트 크기의 bitset 선언 -> key를 가지고 있는 상태인지
}Pos;



int BFS(int a, int b) {
    queue <Pos> q;
    Pos p;
    p.x = a;
    p.y = b;
    p.keys.reset(); // 키의 상태를 0으로 초기화해서 집어넣음
    q.push(p);
    visited[a][b][0] = 1; //시작노드 방문

    while (!q.empty()) {
        auto cur = q.front();
        int dim = (int)cur.keys.to_ulong(); //현재 차원(열쇠 얻은 상태 기반)
        q.pop();

        //cout << cur.x << cur.y << " "<< dim << visited[cur.x][cur.y][dim]<<"\n";

        //도착했다면 -> 최단거리
        if (map[cur.x][cur.y] == '1') {
            return visited[cur.x][cur.y][dim] - 1;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            //범위
            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            //벽
            if (map[nx][ny] == '#')continue;

            //1. 열쇠를 만났을 때 (key 값이 0~5)이면
            int key = (int)(map[nx][ny]) - 97; //a면0 f면 5
            if (key >= 0 && key < 6) {
                //이미 열쇠를 가지고 있을 때, 열쇠를 처음봐서 상태를 갱신해야할 때
                //두 가지 상관없이 해당 노드로는 이동가능하지만 열쇠 상태 갱신해야함.(차원 변경)
                Pos tempP;
                tempP.x = nx;
                tempP.y = ny;
                tempP.keys = cur.keys; //우선 현재노드의 상태를 이어받음
                tempP.keys.set(key, 1); //key번째 비트를 1로만듬 ex) key 가 0이면 a임

                //키를 가지면 상태가 변하므로 차원 바뀜
                int nDim = (int)tempP.keys.to_ulong(); //바뀐 차원 차원(열쇠 얻은 상태 기반)

                //이미 방문한 노드면 넘어감
                if (visited[nx][ny][nDim] != 0)continue;
                q.push(tempP);
                visited[nx][ny][nDim] = visited[cur.x][cur.y][dim] + 1;
                continue;
            }

            //2. 문을 만났을 때
            int door = (int)(map[nx][ny]) - 65; //A면 0 F면 5
            if (door >= 0 && door < 6) {
                //이미 방문했으면 못감
                if (visited[nx][ny][dim] != 0)continue;
                //현재 key를 가지고 있지 않으면 -> 문노드로 방문 불가
                if (cur.keys[door] == 0) continue;
                //가지고 있으면 방문가능
                Pos tempP;
                tempP.x = nx;
                tempP.y = ny;
                tempP.keys = cur.keys; //우선 현재노드의 상태를 이어받음
                q.push(tempP);
                //현재 차원에서 방문
                visited[nx][ny][dim] = visited[cur.x][cur.y][dim] + 1;
                continue;
            }

            //3. 그냥 이동할 수 있는 노드일 때 (현재 차원 그대로)
            if (map[nx][ny] == '.' || map[nx][ny] == '1'|| map[nx][ny] == '0') {
                //방문했으면 못감
                if (visited[nx][ny][dim] != 0)continue;
                Pos tempP;
                tempP.x = nx;
                tempP.y = ny;
                tempP.keys = cur.keys;
                q.push(tempP);
                //현재 차원에서 방문
                visited[nx][ny][dim] = visited[cur.x][cur.y][dim] + 1;
                continue;
            }
        }
    }
    return -1;
}


int main() {

    cin >> row >> col;

    int sx, sy; //시작위치


    //노드 입력
    for (int i = 0; i < row; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < col; j++) {
            map[i][j] = s[j];
            if (s[j] == '0') {
                sx = i;
                sy = j;
            }
        }
    }

    cout << BFS(sx, sy);




    return  0;
}