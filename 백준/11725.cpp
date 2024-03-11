#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100003
vector<int> graph[MAX];
int ans[MAX];
bool visited[MAX];
void bfs() {
    queue<int> q;
    visited[1] = true;
    q.push(1);
    while(!q.empty()) {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < graph[parent].size(); i++) {
            int child = graph[parent][i];
            if (!visited[child]) {
                ans[child] = parent;
                visited[child] = true;
                q.push(child);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y = 0;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs();
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}