#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
#include <algorithm>

#define MAX 803
#define INF INT_MAX

using namespace std;

int N, E;
vector<pair<int, int>> adj[MAX]; //인접행렬
long long dist[MAX];
long long dist1[MAX]; //v1을 위한
long long dist2[MAX]; //v2를 위한

int v1, v2; //거쳐야하는 노드

//미리 준비된 배열을 받아서 해당 테이블을 채움
void dijkstra(int start, long long* arr) {
    arr[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({ arr[start], start });

    while (!heap.empty()) {
        auto cur = heap.top();
        heap.pop();
        int distance = cur.first;
        int idx = cur.second;

        if (distance > arr[idx])continue;

        for (auto next : adj[idx]) {
            int cost = next.first;
            int nidx = next.second;
            if (arr[nidx] > cost + distance) {
                arr[nidx] = cost + distance;
                heap.push({ arr[nidx], nidx });
            }
        }
    }

    return;
}



int main() {
    cin >> N >> E;

    for (int i = 0; i <= N; i++) {
        dist[i] = INF;
        dist1[i] = INF;
        dist2[i] = INF;
    }

    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back({ cost, to });
        adj[to].push_back({ cost, from }); //양방향 간선
    }

    cin >> v1 >> v2;

    dijkstra(1, dist);
    dijkstra(v1, dist1);
    dijkstra(v2, dist2);

    //각 dist 테이블 업데이트



    long long ans = min(dist[v1] + dist1[v2] + dist2[N], dist[v2] + dist2[v1] + dist1[N]);
    //최단경로가 존재하지 않는다는 것은 테이블에서 해당 노드가 INF인 채로 남아있다는 것.
    //즉, 저기에서 ans로 된 값이 INF보다 크다면..? 경로가 존재하지 않는다는 것
    //-> INF를 충분하게 크게 잡았을 때 그렇다. 그래서 INT_MAX로 바꿈

    if (ans >= INF) {
        cout << "-1" << '\n';
    }
    else {
        cout << ans << '\n';
    }



    return 0;
}
