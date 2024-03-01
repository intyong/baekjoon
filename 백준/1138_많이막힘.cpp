#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> v;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (v[i] == count) {
                if (ans[j] == 0) {
                    ans[j] = (i + 1);
                    break;
                }
            }
            else {
                if (ans[j] == 0) count++;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}