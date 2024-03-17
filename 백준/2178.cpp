#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 104
using namespace std;
int map[MAX][MAX] = { 0 };
int ans[MAX][MAX] = { 0 };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    map[x][y] = 0;
    ans[x][y] = 1;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] > 0 && map[x + dx[i]][y] == 1) {
                map[x + dx[i]][y] = 0;
                q.push({x + dx[i], y});
                ans[x + dx[i]][y] = (ans[x][y] + 1);
            }
            if (y + dy[i] > 0 && map[x][y + dy[i]] == 1) {
                map[x][y + dy[i]] = 0;
                q.push({x, y + dy[i]});
                ans[x][y + dy[i]] = (ans[x][y] + 1);
            }
        }
    }
}
int main() {
    int n, m = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            if (temp[j] == '1') map[i + 1][j + 1] = 1;
        }
    }
    bfs(1, 1);
    
    cout << ans[n][m];
}