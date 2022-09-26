#include<bits/stdc++.h>

using namespace std;

int arr[1001][1001];


struct group{
    int num;
    int size;
};

group gSize[1001][1001];

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
int n,m;
int size1;
bool visited[1001][1001];
vector<pair<int,int>> temp; //그룹인 좌표들

int count1 = 0;
void DFS(int r, int c){
    visited[r][c] = true;
    count1++; //외부 변수로 DFS로 탐색한 모든 노드의 개수
    temp.push_back({r,c}); //그룹인 좌표 넣기
    for(int dir = 0; dir<4; dir++){
        int nr = dr[dir] + r;
        int nc = dc[dir] + c;
        if(nr <0 || nc < 0 || nr >= n || nc >= m)continue;
        if(arr[nr][nc] == 1 && visited[nr][nc] == false){
            DFS(nr,nc);
        }
    }
}

int ans = 0;

int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int val;
            cin >> val;
            arr[i][j] = val;
        }
    }
    
    
    
    //그룹화 + size
    int num = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int val = arr[i][j];
            //1이면서 그룹에 해당하지 않는 1일 때 (방문하지 않은 1)
            if(val == 1 && visited[i][j] == false){
                DFS(i,j);
                for(auto x : temp){
                    group g;
                    g.num = num;
                    g.size = count1;
                    gSize[x.first][x.second] = g;
                }
                count1 = 0;
                size1 = 0; //사이즈 초기화
                temp.clear(); //그룹 좌표 초기화
                num++; //그룹 번호 갱신
            }
            
        }
    }
    
    
    //모든 0에 대하여 인접칸 조사
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int val = arr[i][j];
            if(val == 0){
                vector<int> groupNum;
                int maxSize = 1; // 0은 1로 바뀔거니까.
                
                for(int dir = 0; dir<4; dir++){
                    int nr = dr[dir] + i;
                    int nc = dc[dir] + j;
                    if(nr <0 || nc < 0 || nr >= n || nc >= m)continue;
                    //인접칸이 1이라면
                    if(arr[nr][nc] == 1){
                        //해당 칸의 그룹 넘버 확인
                        auto g = gSize[nr][nc];
                        //계산한 그룹이 아니라면 추가
                        if(find(groupNum.begin(), groupNum.end(), g.num) == groupNum.end()){
                            groupNum.push_back(g.num);
                            maxSize += g.size;
                            
                            //cout <<i << j <<" "<< g.num <<  g.size << '\n';
                        }
                    }
                }
                
                ans = max(ans, maxSize);
            }

        }
    }
    
    cout << ans << '\n';
    
    
    return 0;
}