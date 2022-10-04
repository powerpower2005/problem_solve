#include <bits/stdc++.h>

using namespace std;


vector<pair<int,int>> node[10001];
bool visited[10001];



bool check(int s, int e, int mid){
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        //cout << cur << '\n';
        if(cur == e){
            return true;
        }
        for(auto nxt : node[cur]){
            if(nxt.second < mid)continue;
            if(visited[nxt.first] == true)continue;
            q.push(nxt.first);
            visited[nxt.first] = true;
        }
    }
    return false;
    
}

int main(){
    int N,M;
    int minW = INT_MAX;
    int maxW = INT_MIN;
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        //양방향
        node[from].push_back({to, cost});
        node[to].push_back({from,cost});
        minW = min(minW, cost);
        maxW = max(maxW, cost);
    }
    int start, end;
    cin >> start >> end;
    int left = minW;
    int right = maxW;
    int ans = minW;
    //mid : 내가 지금 옮기는 무게
    while(left <= right){
        int mid = (left + right) / 2;
        memset(visited, false, sizeof(visited));
        if(check(start, end, mid)){
            left = mid + 1;
            ans = mid;
        }else{
            right = mid - 1;
        }
    }
    
    cout << ans << '\n';
    
    
    
    return 0;
}
