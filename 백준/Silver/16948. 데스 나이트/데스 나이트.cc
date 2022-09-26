#include <bits/stdc++.h>

using namespace std;

int arr[200][200];

int rs,cs;
int rf,cf;

int dr[6] = {-2,-2,0,0,2,2};
int dc[6] = {-1,1,-2,+2,-1,+1};


int main(){
    int n;
    cin >> n;
    cin >> rs >> cs >> rf >> cf;
    
    
    memset(arr, -1, sizeof(arr));
    queue<pair<int,int>> q;
    q.push({rs,cs});
    arr[rs][cs] = 0;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(int dir = 0; dir<6; dir++){
            int nr = dr[dir] + cur.first;
            int nc = dc[dir] + cur.second;
            
            if(nr< 0 || nc < 0 || nr >= n || nc >= n)continue;
            if(arr[nr][nc] == -1){
                arr[nr][nc] = arr[cur.first][cur.second] + 1;
                q.push({nr,nc});
            }            
        }
    }
    
    cout << arr[rf][cf] << '\n';
    
    return 0;
}