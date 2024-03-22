#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;
int map[MAX][MAX] = { 0 };
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int m, n, k = 0;
vector<int> ans;
int cnt = 0;
void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    int temp = 1;
    map[r][c] = 1;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (r + dr[i] >= 0 && r + dr[i] < m) {
                if (map[r + dr[i]][c] == 0) {
                    q.push({(r + dr[i]), c});
                    map[r + dr[i]][c] = 1;
                    temp++;
                }
            }
            if (c + dc[i] >= 0 && c + dc[i] < n) {
                if (map[r][c + dc[i]] == 0) {
                    q.push({r, (c + dc[i])});
                    map[r][c + dc[i]] = 1;
                    temp++;
                }
            }
        }
    }
    ans.push_back(temp);
}
int main() {
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = m - y2; j < m - y1; j++) {
            for (int k = x1; k < x2; k++) {
                map[j][k] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 0) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}