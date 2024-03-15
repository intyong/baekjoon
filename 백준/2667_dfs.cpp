#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 26
using namespace std;
int map[MAX][MAX] = { 0 };
vector<int> ans;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt = 0;
void dfs(int x, int y) {
    map[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] >= 0 && map[x + dx[i]][y]) dfs(x + dx[i], y);
        if (y + dy[i] >= 0 && map[x][y + dy[i]]) dfs(x, y + dy[i]);
    }
    cnt++;
}
int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++) {
            if (temp[j] == '1') map[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j]) {
                dfs(i, j);
                ans.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}