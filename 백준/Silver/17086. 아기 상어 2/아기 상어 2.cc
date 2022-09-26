#include <bits/stdc++.h>

using namespace std;

int arr[51][51];
int dist[51][51];

vector<pair<int,int>> shark;

int main(){
    //memset은 0과 -1만 초기화 가능
    
    //fill 사용
    fill(dist[0], dist[51], 999);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int val;
            cin >> val;
            arr[i][j] = val;
            if(val == 1){
                shark.push_back({i,j});
            }
        }
    }
    int MM = -1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            //모든 상어 중 안전거리가 가장 작은값 저장
            for(auto sh : shark){
                int sr,sc;
                sr = sh.first;
                sc = sh.second;
                //cout << sr << " "<< sc << '\n';
                dist[i][j] = min(dist[i][j], max(abs(sr-i), abs(sc-j)));
            }
            //가장 안전거리가 작은 값으로 계산
            //cout << dist[i][j] << '\n';
            MM = max(MM, dist[i][j]);
        }   
    }
    
    cout << MM << '\n';
    
    return 0;
}