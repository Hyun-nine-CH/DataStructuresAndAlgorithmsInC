#include <iostream>
using namespace std;

int L[26], R[26];

void preorder(int u) {
    if (u==-1) return;
    cout<<char('A'+u);
    preorder(L[u]);
    preorder(R[u]);
}

void inorder(int u) {
    if (u == -1) return;
    inorder(L[u]);
    cout << char('A'+u);
    inorder(R[u]);
}

void postorder(int u) {
    if(u==-1) return;
    postorder(L[u]);
    postorder(R[u]);
    cout<<char('A'+u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;

    for (int i=0; i<26; ++i) L[i]=R[i]=-1;

    for (int i=0; i<N; ++i) {
        char p, lc, rc;
        cin >> p >> lc >> rc;
        int u=p-'A';
        L[u]=(lc=='.') ? -1 : (lc-'A');
        L[u]=(rc=='.') ? -1 : (rc-'A');
    }
    preorder(0); cout<<'\n';
    inorder(0); cout<<'\n';
    postorder(0); cout<<'\n';
    return 0;
}