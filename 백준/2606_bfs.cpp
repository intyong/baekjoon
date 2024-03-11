#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 103
vector<int> graph[MAX];
bool visited[MAX];
int ans = 0;
void bfs() {
    queue<int> q;
    visited[1] = true;
    q.push(1);
    while(!q.empty()) {
        int first = q.front();
        q.pop();
        for (int i = 0; i < graph[first].size(); i++) {
            int second = graph[first][i];
            if (!visited[second]) {
                q.push(second);
                visited[second] = true;
                ans++;
            }
        }
    }
}
int main() {
    int n = 0;
    cin >> n; // 컴퓨터의 개수
    int m = 0;
    cin >> m;   // 링크의 개수
    for (int i = 0; i < m; i++) {
        int start, end = 0;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    bfs();
    cout << ans;
}