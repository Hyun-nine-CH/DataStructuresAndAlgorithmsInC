#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> a;
vector<int> used;
vector<int> pick;

// dfs func
void dfs() {
    if((int)pick.size()==M){ // the reason is size_t != int
        for (int x : pick){
            cout<<x<<' ';
        }
        cout<<'\n';
    return;
    }
    for(int i=0; i<N; i++){
        if (used[i]) continue; // 주의
        used[i]=1;
        pick.push_back(a[i]);
        dfs();
        pick.pop_back();
        used[i]=0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    a.resize(N);
    for(int i=0; i<N; i++) a[i]=i+1;
    used.assign(N,0);

    dfs();
} // vector.resize(), vector.assign(,) 주의