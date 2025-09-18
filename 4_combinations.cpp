#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> a, pick;

void dfs(int idx, int taken){
    if(taken==K){
        for(int x : pick) cout<<x<<' ';
        cout<<'\n';
        return;
    }
    if(idx==N) return;

    pick.push_back(a[idx]);
    dfs(idx+1,taken+1);
    pick.pop_back();

    dfs(idx+1,taken);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>K;
    a.resize(N);
    for(int i=0;i<N;i++) a[i]=i+1;
    dfs(0,0);
}