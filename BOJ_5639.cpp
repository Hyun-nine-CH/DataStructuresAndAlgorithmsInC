#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder;

// [l, r) (l<=idx<r)에서 트리를 후위 순회로 출력하는 함수
void postorder(int l, int r) {
    if (l>=r) return; // 구간이 비었으면 종료
    int root=preorder[l]; // 전위 순회의 첫 원소가 현재 서브트리의 루트

    // m -> 오른쪽 서브트리 시작 위치를 찾기
    int m=l+1;
    while(m<r && preorder[m]<root) m++; // preorder[l+1]<root, l<m<r
    // preorder[l+1 ~ m-1] 구간 -> 왼쪽 서브트리
    // preorder[m ~ r-1] 구간 -> 오른쪽 서브트리

    postorder(l+1,m); // 왼쪽 서브트리를 후위 순회
    postorder(m,r); // 오른쪽 서브트리를 후위 순회
    cout<<root<<'\n'; // 마지막에 루트 출력 (후위 순회의 규칙)
}

int main() {
    ios::sync_with_stdio(false); // C I/O와 동기화 비활성화 -> 속도 향상
    cin.tie(nullptr); // cin과 cout 묶음을 해제 -> 속도 향상

    int x;
    // 입력이 EOF까지 주어지므로, 더 이상 읽을 수 없을 때까지 반복

    while (cin>>x) {
        preorder.push_back(x); // 전위 순회 값들을 벡터에 저장
    }

    postorder(0, preorder.size()); // 전체 구간 [0,N)에서 후위 순회 시작
    return 0;
}