#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    float t = round(n * 0.15);
    float ans = 0;
    int count = 0;
    for (int i = t; i < (v.size() - t); i++) {
        ans += v[i];
        count++;
    }
    ans /= count;
    ans = round(ans);
    cout << ans;

    return 0;
}