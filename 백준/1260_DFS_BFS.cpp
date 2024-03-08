#include <iostream>
#include <queue>
using namespace std;
#define MAX_SIZE 1003
int dfs[MAX_SIZE][MAX_SIZE] = { 0 };
int bfs[MAX_SIZE][MAX_SIZE] = { 0 };
int visited[MAX_SIZE] = { 0 };
queue<int> q;
void insert_edge(int start, int end) {
    dfs[start][end] = 1;
    dfs[end][start] = 1;
    bfs[start][end] = 1;
    bfs[end][start] = 1;
}
void do_dfs(int n, int m) {
    visited[n] = 1;
    cout << n << ' ';
    for (int i = 1; i <= m; i++) {
        if (dfs[n][i] && !visited[i]) do_dfs(i, m);
    }
}
void do_bfs(int n, int m) {
    visited[n] = 1;
    cout << n << ' ';
    q.push(n);
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        for (int i = 1; i <= m; i++) {
            if (bfs[temp][i] && !visited[i]) {
                visited[i] = 1;
                q.push(i);
                cout << i << ' ';
            }
        }
    }
}
int main() {
    int n, m, v = 0;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int start, end = 0;
        cin >> start >> end;
        insert_edge(start, end);
    }
    do_dfs(v, n);
    cout << endl;
    for (int i = 0; i < MAX_SIZE; i++) visited[i] = 0;
    do_bfs(v, n);
}