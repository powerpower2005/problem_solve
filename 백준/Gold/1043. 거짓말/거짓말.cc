#include <bits/stdc++.h>

using namespace std;


int parent[51];

int find(int X){
    if(parent[X] < 0){
        //부모 노드가 없으면 자신이 부모노드가 될 후보
        return X;
    }
    return parent[X] = find(parent[X]);
}

void unionFind(int u, int v){
    int p_u = find(u);
    int p_v = find(v);
    //같으면 생략
    if(p_u == p_v)return;
    
    //u의 트리 노드가 더 많음
    //v를 u의 밑에 추가시킴
    if(p_u <= p_v){
        parent[p_u] = parent[p_u] + parent[p_v];
        parent[p_v] = p_u;
    }else{
        parent[p_v] = parent[p_u] + parent[p_v];
        parent[p_u] = p_v;
    }
}

//0번이 나임

int main(){
    
    fill(parent, parent+51, -1);
    
    int N,M;
    cin >> N >> M;
    int truth;
    cin >> truth;
    
    //진실을 아는 사람은 나와 아는 사람
    for(int i = 0; i<truth; i++){
        int p;
        cin >> p;
        unionFind(0, p);
    }
    //파티
    vector<int> vec[50];
    for(int i = 0; i<M; i++){
        int people;
        cin >> people;
        
        for(int j = 0; j<people; j++){
            int pp;
            cin >> pp;
            vec[i].push_back(pp);
        }
        //파티의 사람들에대해서 union Find
        for(int a = 0; a<vec[i].size(); a++){
            for(int b = a+1; b<vec[i].size(); b++){
                unionFind(vec[i][a], vec[i][b]);
            }
        }
    }
    
    int count = 0;
    //파티의 개수만큼만 조사
    for(int k = 0; k<M; k++){
        bool isPossible = true;
        for(auto x : vec[k]){
            //cout << find(x) << '\n';
            if(find(x) == 0){
                isPossible = false;
                break;
            }
        }
        if(isPossible)count++;
    }
    
    
    cout << count << '\n';
    
    
    return 0;
}