#include <iostream>
#include <vector>
#include <queue>
#define MAX 1002
using namespace std;
int map[MAX][MAX] = { 0 };
int visited[MAX] = { 0 };
int n = 0;  // 정점의 개수
int m = 0;  // 간선의 개수
int start = 0;  // 탐색의 시작점
void dfs(int start) {
    cout << start << ' ';
    visited[start] = 1;
    for (int i = 0; i <= n; i++) {
        if (!visited[i] && map[start][i]) {
            dfs(i);
        }
    }
}
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        cout << temp << ' ';
        for (int i = 0; i <= n; i++) {
            if (!visited[i] && map[temp][i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
int main() {
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++) {
        int one, two = 0;
        cin >> one >> two;
        map[one][two] = 1;
        map[two][one] = 1;
    }
    dfs(start);
    for (int i = 0; i <= n; i++) visited[i] = 0;
    cout << endl;
    bfs(start);
}