#include <iostream>
#include <vector>
using namespace std;

int N, target;
vector<int> a;
vector<int> take;

long long cnt=0;

void dfs(int idx, int sum){
    if(idx==N){
        if(sum==target){
            // cnt++;
            // for(int x : take) cout<<x<<' ';
            // cout<<'\n';
        }
        return;
    }
    take.push_back(a[idx]);
    dfs(idx+1,sum+a[idx]);
    take.pop_back();
    dfs(idx+1,sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>target;
    a.resize(N);
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    dfs(0,0);
    cout<<"count="<<cnt<<'\n';
}