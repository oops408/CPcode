#include <bits/stdc++.h>
using namespace std;

int t, n, a[1000005];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        ans = max(ans, cnt);
        if (ans & 1) ans++;
        cout << ans << endl;
    }
    return 0;
}
