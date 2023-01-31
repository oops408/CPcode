#include <bits/stdc++.h> 
#define inf 0x3f3f3f3f
using namespace std; 

int d, n, m, u, v, w, head[1005], cnt, ans, in[1005];
bool vis[1005];
struct Edge {
    int v, next, w;
} e[10005]; 

void addEdge(int u, int v, int w) {
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
} 

bool sort() {
    queue<int> q;
    int k = 0;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = true;
        k = max(k, ans - u);
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            in[v]--;
            if (w == 1) ans = max(ans, v);
            if (in[v] == 0) q.push(v);
        }
    } 
    return k == ans;
}

int main() {
    scanf("%d", &d);
    while (d--) {
        scanf("%d%d", &n, &m);
        memset(head, -1, sizeof head);
        memset(in, 0, sizeof in);
        memset(vis, false, sizeof vis);
        cnt = 0;
        ans = -inf;
        while (m--) {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            in[v]++;
        }
        if (!sort()) {
            printf("NO\n");
        } else {
            printf("%d\n", ans);
        }
    } 
    return 0;
}