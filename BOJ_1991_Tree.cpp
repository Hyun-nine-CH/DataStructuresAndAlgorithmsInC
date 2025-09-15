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