#include <iostream>
#include <vector>

using namespace std;

const int N = 1005;
vector<int> g[N];
bool st[N];

int dfs(int u) {
    st[u] = true;
    int res = u;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (st[v]) {
            return res + v;
        } else {
            int t = dfs(v);
            if (t > res) {
                res = t;
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != -1) {
            g[x].push_back(i);
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            st[j] = false;
        }
        int t = dfs(i);
        if (t > ans) {
            ans = t;
        }
    }
    cout << ans << endl;
    return 0;
}
