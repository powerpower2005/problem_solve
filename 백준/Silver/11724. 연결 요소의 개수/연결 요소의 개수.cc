#include<iostream>
#include<vector>
#include<stack>


using namespace std;

int N, M ; // 노드, 간선
vector<int> node[1001]; // 노드에 연결된 노드의 정보를 담는 배열 ex) 1번 노드에 연결된 정보를 가리키는 벡터가 있음
int visited[1001];
int cnt = 0;

stack<int> stk; //DFS를 위함

void DFS(int x){
    int size = node[x].size();
    for(int i = 0; i<size; i++){
        int nextNode = node[x][i];
        if(visited[nextNode] == false){
            visited[nextNode] = true;
            DFS(nextNode);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    /*
    //이렇게 하려면... 사전순으로 정리해야함 -> 입력을 사전순으로 받아야함.
    for(int i = 0; i<M; i++){
        int a,b;
        cin >> a >> b;
        //어느 한 노드라도 이미 방문되었다면 -> 그것은 연결되어있는 요소
        if(visit[a] != 0 || visit[b] != 0){
            visit[a] = 1;
            visit[b] = 1;
        }else{ // 둘다 방문하지 않았으면 새로운 연결요소
            visit[a] = 1;
            visit[b] = 1;
            cnt++;
        }
    }
    */
    
    //노드에 연결상태를 담고싶음
    for(int i = 1; i<= M; i++){
        int n1, n2;
        cin >> n1 >> n2;
        //n1노드에 연결된 n2 상태추가 , 쌍방향이므로 n2에 n1정보 추가
        node[n1].push_back(n2);
        node[n2].push_back(n1);
        
    }
    
    //DFS나 BFS 조사
    //전 노드에 대해서
    for(int i = 1; i<=N; i++){
        
        //방문했으면 다음 거
        if(visited[i] == 1) continue;
        
        //방문안했으면 
        stk.push(i);
        cnt++;
        visited[i] = 1;
        DFS(i);
        // DFS 실행

    }

    cout << cnt;
}