#include <iostream>
#define MAX 1002
using namespace std;
int map[MAX][MAX] = { 0 };
int visited[MAX] = { 0 };
int n = 0;  // 정점의 개수
int m = 0;  // 간선의 개수
int ans = 0;
void dfs(int x) {
    visited[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (map[x][i] && !visited[i]) {
            dfs(i);
        }
    }
}
int main() {
    cin >> n >> m;
    if (m == 0) {
        cout << n;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v = 0;
        cin >> u >> v;
        map[u][v] = 1;
        map[v][u] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans;
}