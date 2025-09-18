#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int N,M;
vector<string> grid;
vector<vector<int>> dist;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    grid.resize(N);
    for(int i=0;i<N;i++) cin>>grid[i];

    dist.assign(N,vector<int>(M,-1));

    queue<pair<int,int>> q;
    if (grid[0][0]=='1'){
        dist[0][0]=0;
        q.push({0,0});
    }

    while(!q.empty()){
        auto [x,y]=q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            if(grid[nx][ny]=='0') continue; // 벽
            if(dist[nx][ny]!=-1) continue; // 방문됨
            dist[nx][ny]=dist[x][y]+1;
            q.push({nx,ny});
        }
    }
    cout<<dist[N-1][M-1]<<"\n"; // 도달 불가면 -1
}