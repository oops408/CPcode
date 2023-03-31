#include <bits/stdc++.h>
#define ll long long
#define go ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int const N = 2e5 + 10;

int dfs(int s, int a[])
{
    return a[s] == -1 ? 1 : 1 + dfs(a[s], a);
}

void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dfs(i, a));
    }
    cout << ans;
}

int main()
{
    int t = 1;
    // cin>>t;
    // go;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}