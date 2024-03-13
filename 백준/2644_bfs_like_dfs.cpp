#include <iostream>
#include <vector>
#include <queue>
#define MAX 103
using namespace std;
vector<int> graph[MAX];
int visited[MAX];
void bfs(int one) {
    queue<int> q;
    q.push(one);
    visited[one] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++) {
            int temp = graph[now][i];
            if (!visited[temp]) {
                q.push(temp);
                visited[temp] = (visited[now] + 1);
            }
        }
    }
}
int main() {
    int n = 0;
    cin >> n;
    int one, two = 0;
    cin >> one >> two;
    int m = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int start, end = 0;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    bfs(one);
    cout << (visited[two] - 1);
    return 0;
}