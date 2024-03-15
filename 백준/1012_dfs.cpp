#include <iostream>
#define MAX 2503
using namespace std;
int map[MAX][MAX] = { 0 };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m = 0;  // 가로 길이
int n = 0;  // 세로 길이
int k = 0;  // 배추의 개수
int ans = 0;    // 정답
void init() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            map[i][j] = 0;
        }
    }
    ans = 0;
}
void dfs(int x, int y) {
    map[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        if ((x + dx[i]) >= 0 && map[x + dx[i]][y]) dfs(x + dx[i], y);
        if ((y + dy[i]) >= 0 && map[x][y + dy[i]]) dfs(x, y + dy[i]);
    }
}
int main() {
    int t = 0; // 케이스 개수
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            int x, y = 0;
            cin >> x >> y;
            map[x][y] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
        init();
    }
}