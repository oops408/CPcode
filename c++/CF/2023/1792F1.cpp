#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n, dp[5005][2];

int main() {
    cin >> n;
    dp[2][0] = dp[2][1] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i][0] = (dp[i-1][1] * (i-1)) % mod;
        dp[i][1] = (dp[i-1][0] * (i-1)) % mod;
    }
    cout << (dp[n][0] + dp[n][1]) % mod << endl;
    return 0;
}
