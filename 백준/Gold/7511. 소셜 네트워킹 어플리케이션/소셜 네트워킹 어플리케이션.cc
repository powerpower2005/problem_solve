#include <bits/stdc++.h>

using namespace std;

//분리가 되어있는지 찾는 문제로 루트가 다르면.. 다른 집합
int parent[1000001]; //부모집합

//가장 위의 부모를 반환
int findParent(int X) {
    //처음 나왔다면 그것이 부모
	if (parent[X] == -1) {
		return X;
	}
	return parent[X] = findParent(parent[X]);
}

void unionNode(int a, int b){
    int P_a = findParent(a);
    int P_b = findParent(b);
    if(P_a != P_b){
        parent[P_b] = P_a;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        cout << "Scenario " <<i+1 <<":\n";
        memset(parent, -1, sizeof(parent));
        
        int number;
        int relations;
        cin >> number >> relations;
        
        //각 노드들을 union
        for(int i = 0; i<relations; i++){
            int a,b;
            cin >> a >> b;
            unionNode(a,b);
        }
        
        
        int m;
        cin >> m;
        for(int i = 0; i<m; i++){
            int u,v;
            cin >> u >> v;
            
            if(findParent(u) == findParent(v)){
                cout << "1" << '\n';
            }else{
                cout << "0" << '\n';
            }
            
        }
        cout << '\n';
    }
    
    return 0;
}