#include <bits/stdc++.h>

using namespace std;

vector<int> friends[2001];
bool visit[2001];
bool isPossible = false;


void DFS(int node, int depth){
    visit[node] = true;
    if(depth >= 5){
        isPossible = true;
        visit[node] = false;
        return;
    }
    int size = friends[node].size();
    for(int i = 0; i<size; i++){
        int nextNode = friends[node][i];
        if(visit[nextNode] == false){
            DFS(nextNode, depth + 1);
        }
    }
    visit[node] = false;
}


int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int u,v;
        cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }
    
    for(int i = 0; i<m; i++){
        DFS(i,1);
        if(isPossible)break;
    }
    
    if(isPossible){
        cout << "1\n";
    }else{
        cout << "0\n";
    }
    
    
    
    
    return 0;
}