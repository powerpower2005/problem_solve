#include <bits/stdc++.h>

using namespace std;

int arr[21][21];

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
int visited[21][21];
queue<pair<int,int>> q;

int n,m;

int check(){
    int cnt = 0;
    int compare = 0;
    fill(visited[0], visited[21], 0);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(visited[i][j] == 1)continue;
            if(arr[i][j] == 2){
                bool canDelete = true;
                q.push({i,j});
                visited[i][j] = 1;
                cnt++;
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    
                    for(int dir = 0; dir<4; dir++){
                        int nr = dr[dir] + cur.first;
                        int nc = dc[dir] + cur.second;
                        if(nr < 0 || nc < 0 || nr >= n || nc >= m)continue;
                        if(arr[nr][nc] == 0){canDelete = false;}
                        if(arr[nr][nc] == 2 && visited[nr][nc] == 0){
                            visited[nr][nc] = 1;
                            q.push({nr,nc});
                            cnt++;
                        }
                    }
                }
                if(canDelete){
                    compare += cnt;
                }
                //cout << compare << '\n';
                cnt = 0;
            }
        }
    }
    return compare;
}

int main(){
    
    int ans = 0;
    cin >> n >> m;
    
    vector<pair<int,int>> enemy;
    //0 : 빈칸, 1: 내 돌, 2 : 상대 돌(내가 없애야 할)
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int val;
            cin >> val;
            arr[i][j] = val;
            if(val == 2){
                enemy.push_back({i,j});
            }
        }
    }
    
    vector<pair<int,int>> space;
    //2번 돌에 대해서 주변에 빈칸 위치 파악
    for(auto x : enemy){
        int r = x.first;
        int c = x.second;
        for(int dir = 0; dir<4; dir++){
            int nr = dr[dir] + r;
            int nc = dc[dir] + c;
            if(nr < 0 || nc < 0 || nr >= n || nc >= m)continue;
            if(arr[nr][nc] == 0){
                space.push_back({nr,nc});
                //cout << nr << nc << '\n';
            }
        }
        
    }
    
    
    //이 빈칸에 대해서 2개를 뽑아서 조합을 만듦 => 2개를 못뽑는 경우가 있음.
    int len = space.size();
    if(len == 1){
        arr[space[0].first][space[0].second] = 1;
        int tmp = check(); //없어지는 돌의 개수 체크
        arr[space[0].first][space[0].second] = 0;
        ans = max(ans, tmp);
    }
    for(int i = 0; i<len-1; i++){
        for(int j = i+1; j<len; j++){
            auto one = space[i];
            auto two = space[j];
            arr[one.first][one.second] = 1;
            arr[two.first][two.second] = 1;
            //cout << one.first << one.second << " " << two.first << two.second << '\n';
            int tmp = check(); //없어지는 돌의 개수 체크
            arr[one.first][one.second] = 0;
            arr[two.first][two.second] = 0;
            ans = max(ans, tmp);
        }
    }
    
    cout << ans << '\n';
    return 0;
}