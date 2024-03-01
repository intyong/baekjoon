#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool com(const pair<int,int> &a,const pair<int,int> &b) {
       return a.second<b.second;
}
int main() {
    int n = 0;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        v.push_back({temp, (i + 1)});
    }
    sort(v.begin(), v.end());
    int temp = 0;
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            temp = v[i].first;
            v[i].first = count;
        }
        else {
            if (v[i].first != temp) {
                temp = v[i].first;
                v[i].first = ++count;
            }
            else v[i].first = count;
        }
    }
    sort(v.begin(), v.end(), com);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << ' ';
    }
}