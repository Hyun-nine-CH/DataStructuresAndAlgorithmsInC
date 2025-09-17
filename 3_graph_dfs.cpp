#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> g;
vector<int> vis;

void dfs(int u){
    vis[u]=1;
    for(int v : g[u]){
        if(!vis[v]) dfs(v);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    g.assign(N+1,{});
    vis.assign(N+1,0);
    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
}