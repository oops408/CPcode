#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int n, ans, a[100100];
map<int, int> m;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    int maxbit = 0;
    for (int i = 1; i <= n; i++) {
        maxbit = max(maxbit, (int)log2(a[i]) + 1);
    }
    for (int i = maxbit - 1; i >= 0; i--) {
        int cnt = 0;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (((it->first) >> i) & 1) {
                cnt += it->second;
            }
        }
        ans = (ans * 2ll + 1ll * cnt * (cnt - 1) / 2 % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}
