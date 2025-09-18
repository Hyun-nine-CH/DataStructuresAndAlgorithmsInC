/*
// 0-1 BFS
deque<int> dq;
dist[start]=0;
dq.push_back(start);
while(!dq.empty()){
    int u=dq.front(); dq.pop_front();
    for(auto [v,w]:g[u]){
        if(dist[v]>dist[u]+w){
            dist[v]=dist[u]+w;
            if(w=0) dq.push_front(v);
            else dq.push_back(v);
        }
    }
} // 간선 가중치가 0 또는 1일 때, Dijkstra보다 빠르게 해결
*/

/*
//sliding windows_min/max
deque<int> dq;
for(int i=0;i<N;i++){
    while(!dq.empty() && dq.front()<=i-K) dq.pop_front(); // out of windows
    while(!dq.empty() && arr[dq.back()]<=arr[i]) dq.pop_back(); // monotonically decreasing
    dq.push_back(i);
    if(i>=K-1) cout<<arr[dq.front()]<<"\n"; // in this place, maximum
}
*/

/* 위 2가지 케이스가 deque의 전부 */

// 무가중치 그래프 BFS -> 모든 간선 가중치가 1일 때, queue
/*
void bfs(int s){
    queue<int> q;
    dist.assign(N+1,-1);
    dist[s]=0;
    q.push(s);

    while(!q.empty()){
        int u=1.front(); q.pop();
        for(int v:g[u]){
            if(dist[v] != -1) continue;
            dist[v]=dist[u]+1;
            1.push(v);
        }
    }
} // 기존에 적용했던 queue 방식
*/

/*
// 0-1 BFS, 가중치가 0/1일 때, deque 사용
// 전제: vector<vector<pair<int,int>>> g;
void bfs01(int s){
    deque<int> dq;
    dist.assign(N+1, 1e9); // 도달 불가 = 큰 값으로 거리 배열 초기화 / 방문 체크 겸함
    dist[s]=0;
    dq.push_back(s); // 시작점을 덱 뒤에 넣고 시작

    while(!dq.empty()){ // 덱이 빌 때까지 반복
        int u=dq.front(); dq.pop_front(); // 가장 가까운 레벨에 있는 정점 하나 꺼냄
        for(auto [v,w]:g[u]){ // u의 모든 인접 (v, 간선가중치 w) 탐색
            if(dist[v]>dist[u]+w){ // 완화: u를 통해 v로 더 짧게 갈 수 있나?
                dist[v]=dist[u]+w; // v 최단 거리 갱신
                if(w=0) dq.push_front(v); // 0 가중치 -> 같은 레벨이므로 앞쪽에 넣어 즉시 처리
                else dq.push_back(v); // 1 가중치 -> 다음 레벨이므로 뒤쪽에 넣어 나중 처리
            }
        }
    }
}
*/

/*
// Dijkstra (양수 가중치 기반)
// 가중치가 1,2,3,... 등 일반일 때 -> priority_queue 사용
// (거리, 정점) 쌍을 최소 힙으로 관리하는 우선순위 큐
// 기본 priority_queue는 최대 힙이므로, greator<> 써서 최소 힙으로 바꿈
void dijkstra(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist.assign(N+1, 1e9); // dist[i]=시작점 s에서 i까지의 최단거리 (처음엔 충분한 큰 수, 1e9)
    dist[s]=0;
    pq.push({0,s}); // (거리=0, 정점=s)를 PQ에 삽입

    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop(); // 가장 작은 거리 후보 (d,u)를 꺼냄
        if(d>dist[u]) continue; // 꺼낸 값이 최신 거리보다 크면, 이미 최적 갱신된 상태, -> 무시
        for(auto [v,w]:g[u]){ // u와 연결된 간선들 (v: 이웃 정점, w: 간선 가중치)
            if(dist[v]>dist[u]+w){ // u를 거쳐서 v로 가는 거리가 더 짧으면
                dist[v]=dist[u]+w; // v까지의 최단거리 갱신
                pq.push({dist[v],v}); // (새 거리, 정점 v) PQ에 넣음 -> 추후 처리
            }
        }
    }
}
*/
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <limits>
using namespace std;

int N, M;
vector<vector<pair<int,int>>> g; // (v, w)

//=== BFS (모든 간선 가중치=1) ===
vector<int> bfs(int s){
    vector<int> dist(N+1,-1);
    queue<int> q;
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto [v,w]:g[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist;
}
//=== 0-1 BFS ===
vector<int> bfs01(int s){
    deque<int> dq;
    vector<int> dist(N+1,1e9);
    dist[s]=0;
    dq.push_back(s);
    while(!dq.empty()){
        int u=dq.front(); dq.pop_front();
        for(auto [v,w]: g[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                if(w==0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    return dist;
}
//=== Dijkstra ===
vector<int> dijkstra(int s){
    vector<int> dist(N+1,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [v,w]:g[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
// === main ===
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    g.assign(N+1,{});
    for(int i=0;i<M;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int s=1;
    auto d1=bfs(s);
    auto d2=bfs01(s);
    auto d3=dijkstra(s);

    cout<<"BFS\n";
    for(int i=1;i<=N;i++) cout<<i<<":"<<d1[i]<<" ";
    cout<<"\n";

    cout<<"0-1 BFS\n";
    for(int i=1;i<=N;i++) cout<<i<<":"<<d2[i]<<" ";
    cout<<"\n";

    cout<<"Dijkstra\n";
    for(int i=1;i<=N;i++) cout<<i<<":"<<d3[i]<<" ";
    cout<<"\n";
}