#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> g;
vector<int> dist;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    g.assign(N+1,{});
    dist.assign(N+1,{});
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    int s=1;
    dist[s]=0;
    q.push(s);

    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v : g[u]){
            if(dist[v] != -1) continue;
            dist[v]=dist[u]+1;
            q.push(v);
        }
    }
}