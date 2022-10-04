#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;


//N번의 노드 중 X 위치에서 파티를 연다.
//그래도 그 파티에 오는데 가장 오래걸리는 녀석은?
//X위치에서 출발해서 가장 먼 곳은?
//모두가 최단시간 걸리는 파티 장소는 어디일까?

vector <pair<int,int>> adj[20001]; // 인접행렬 from,(weight,to)

//table[m] : X 노드에서 각 m 번 노드까지의 최단거리
int table[1001];

//toX[n] : n번 노드에서 X까지의 최단거리
int toX[1001];

int N,M,X;


//start 에 대해서 최단거리 table 만들기
void dijkstra(int start){
    
    fill(table, table+N+1, INF);
    
    //최소힙 생성
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minHeap;

    table[start] = 0;
    minHeap.push({table[start], start});
    
    while(!minHeap.empty()){
        auto cur = minHeap.top();
        minHeap.pop();
        
        //거리, to를 뽑음
        int dist = cur.first;
        int idx = cur.second;
        //해당 정점에 대한 최단거리 테이블의 정보와 비교해서 조사해야하는지 확인
        if(table[idx] < dist) continue;
        
        //그렇다면 해당 정점이 갈 수 있는 곳을 알아봄
        //adj[from] = {weight, to}
        for(auto next : adj[idx]){
            int cost = next.first; //해당 정점에 가는데 드는 가중치
            int nidx = next.second; //갈 수 있는 정점
            //해당 정점이 갈 수 있는 거리 중 table에 있는 것보다 작다면 업데이트
            if(table[nidx] > dist + cost){
                table[nidx] = dist+cost;
                minHeap.push({table[nidx], nidx});
            }
        }
    }
}



int main(){
    cin >> N >> M >> X;
    //초기화
    
    for(int i = 0; i<M; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back({cost, to});
    }
    
    
    //i 노드에서 X까지 걸리는 최단거리 구해서 toX에 저장
    for(int i = 1; i<=N; i++){
        dijkstra(i);
        toX[i] = table[X];
    }
    
    //X노드에서 각 노드로 가는 최단거리 저장
    dijkstra(X);
    
    
    
    int ans = -1;
    for(int i = 1; i<=N; i++){
        ans = max(ans, table[i] + toX[i]);
    }
    cout << ans << '\n';
    
    return 0;
}