#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    deque<int> dq;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        if (v[i] == 0) dq.push_front(temp);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        dq.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        cout << dq[i] << ' ';
    }
}