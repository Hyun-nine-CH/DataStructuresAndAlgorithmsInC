#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N,M;
vector<string> grid;
vector<vector<int>> g;
vector<int> dist;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

inline int id(int x, int y){ return x*M + y; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    grid.resize(N);
    for(int i=0;i<N;i++) cin>>grid[i];

    g.assign(N*M,{});
    dist.assign(N*M,-1);

    // graph str: pipeline connection
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            if(grid[x][y]=='0') continue;
            int u=id(x,y);
            for(int dir=0;dir<4;dir++){
                int nx=x+dx[dir], ny=y+dy[dir];
                if(nx<0||nx>=N||ny<0||ny>=M) continue;
                if(grid[nx][ny]=='0') continue;
                int v=id(nx,ny);
                g[u].push_back(v);
            }
        }
    }
    int s=id(0,0), t=id(N-1,M-1);
    if(grid[0][0]=='0'){
        cout<<-1<<"\n";
        return 0;
    }

    queue<int> q;
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v:g[u]){
            if(dist[v]!=-1) continue;
            dist[v]=dist[u]+1;
            q.push(v);
        }
    }
    cout<<dist[t]<<"\n";
}