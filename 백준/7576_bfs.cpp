#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#define MAX 1002
using namespace std;
int map[MAX][MAX] = { 0 };
int ans[MAX][MAX] = { 0 };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int m, n = 0;   // 가로, 세로
void bfs() {
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    if (q.empty()) {
        cout << -1;
        exit(0);
    }
    int temp_1 = q.front().first;
    int temp_2 = q.front().second;
    q.push({temp_1, temp_2});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if ((x + dx[i]) > 0 && (x + dx[i]) <= n) {
                if (map[x + dx[i]][y] == 0) {
                    q.push({(x + dx[i]), y});
                    map[x + dx[i]][y] = 1;
                    ans[x + dx[i]][y] = (ans[x][y] + 1);
                }
            }
            if ((y + dy[i] > 0) && (y + dy[i]) <= m) {
                if (map[x][y + dy[i]] == 0) {
                    q.push({x, (y + dy[i])});
                    map[x][y + dy[i]] = 1;
                    ans[x][y + dy[i]] = (ans[x][y] + 1);
                }
            }
        }
    }
}
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int temp = 0;
            cin >> temp;
            map[i][j] = temp;
            ans[i][j] = temp;
        }
    }
    bfs();
    int max = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ans[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if (ans[i][j] > max) max = ans[i][j];
        }
    }
    cout << (max - 1);
    return 0;
}