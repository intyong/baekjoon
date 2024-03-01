#include <iostream>
using namespace std;
int count_rec = 0;
int count_dp = 0;
int fibo(int n) {
    if (n == 1 || n == 2) {
        count_rec++;
        return 1;
    }
    else return fibo(n - 1) + fibo(n - 2);
}
int main() {
    int n = 0;
    cin >> n;
    int dp[42] = { 0 };
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        count_dp++;
    }
    int temp = fibo(n);
    cout << count_rec << ' ' << count_dp;
    return 0;
}