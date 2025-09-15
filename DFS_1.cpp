#include <iostream>
#include <vector>
using namespace std;

bool visited[9]; // 방문 여부 체크 수용량 크기([0], [1], ... , [8]; bool 자료형의 크기를 갖는 9개의 배열)
vector<int> graph[9]; // vector<int>라는 컨테이너가 총 9개, graph[0], ... , graph[8], 인접리스트

void dfs(int x) {
    visited[x]=true; // x라는 요소를 true로 미리 설정
    cout<<x<<""; // x에 char(문자), string(문자열) 들어감 그리고 그것을 출력

    // x와 연결된 모든 이웃(y)을 순회
    for (int i=0; i<graph[x].size(); i++){ // 0부터 x번째 벡터(배열) 안의 요소의 개수 - 1까지
        int y=graph[x][i]; // y = x번째 벡터(배열) 안의 요소 중 i번째 요소, y = x의 i번째 이웃 노드
        if (!visited[y]) // 만약 그 i번째 배열의 논리값이 false라면,
        dfs(y); // 방문 하지 않았으므로 해당 요소를 dfs 인자에 삽입
    }
}
int main(void) {
    graph[1].push_back(2); // graph[기준 노드], 인접리스트[간선에 따른 말단 노드(연결된 외부 노드)]
    graph[1].push_back(3);
    graph[1].push_back(8);
    graph[2].push_back(1);
    graph[2].push_back(7);
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);
    dfs(1);
}