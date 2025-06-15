#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX = 100001;

vector<int> adj[MAX];
bool visited[MAX];
vector<int> visitOrder;

void dfs_iterative(int start) {
    stack<int> st;
    st.push(start);

    while(!st.empty()) {
        int now = st.top();
        st.pop();

        if(visited[now]) continue;

        visited[now] = true;
        visitOrder.push_back(now);

        for(auto it = adj[now].rbegin(); it != adj[now].rend(); ++it) {
            if(!visited[*it]) {
                st.push(*it);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=N; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs_iterative(1);

    for(int room : visitOrder) {
        cout << room << ' ';
    }
    return 0;

}