#include <iostream> // 입출력 장치
#include <vector> // 배열 벡터를 사용 (벡터 자료구조)
#include <stack> // 스택을 사용하여 하나의 요소를 차근차근 체크해나감
#include <algorithm> // STL 알고리즘 기능 사용
using namespace std; // 표준 출력 모드 사용 및 std:: 생략 가능

const int MAX = 100001; // 방의 최대 제한 개수

vector<int> adj[MAX]; // 인접한 간선의 최대 제한 개수를 저장할 벡터 (간선 리스트)
bool visited[MAX]; // 방문 체크를 위한 boolean 자료형 배열
vector<int> visitOrder; // 방문 순서를 저장할 벡터

void dfs_iterative(int start) {
    stack<int> st; // 스택 객체 하나를 생성하는 지역 변수 선언
    // → 이런 식으로 자료형을 꺾쇠 괄호 < > 안에 넣어서 사용하는 것이 C++ STL의 전형적인 사용 패턴
    // stack<T>는 내부적으로 deque<T>를 기본 컨테이너로 사용하지만, vector나 list로 바꿀 수 있음
    st.push(start); // 벡터 안에 start 요소를 넣었음

    while(!st.empty()) {
        int now = st.top(); // st의 요소들의 제일 윗부분부터 꺼낼 예정
        st.pop(); // 꺼냄

        if(visited[now]) continue; // 이미 방문이 체크된 상태라면 스킵

        visited[now] = true; // 방문 체크 완료 표시
        visitOrder.push_back(now); // 해당 방문 상태를 방문 순서 리스트에 저장

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