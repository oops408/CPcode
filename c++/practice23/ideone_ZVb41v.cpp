#include <bits/stdc++.h>
using namespace std;

int n, t, cnt_i, cnt_o, x, y, v;
char op, buf[100];
bool input[10][10];
bool flag[10][10];
bool value[10][10];
vector<int> e[10][10];

bool Not(int x, int y) {
    return !value[x][y];
}

bool And(int x, int y) {
    return value[x][y];
}

bool Or(int x, int y) {
    return value[x][y];
}

void dfs(int x, int y) {
    if (flag[x][y]) return;
    flag[x][y] = true;
    if (input[x][y]) {
        value[x][y] = (buf[cnt_i++] == '1');
    } else {
        for (int i = 0; i < e[x][y].size(); i++) {
            int to = e[x][y][i];
            int tx = to / 10, ty = to % 10;
            dfs(tx, ty);
        }
        if (op == '!') value[x][y] = Not(x, y);
        if (op == '&') value[x][y] = And(x, y);
        if (op == '|') value[x][y] = Or(x, y);
    }
}

int main() {
    cin >> n;
    while (n--) {
        memset(input, false, sizeof input);
        memset(flag, false, sizeof flag);
        memset(value, false, sizeof value);
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                e[i][j].clear();
        while (cin >> buf, buf[0] != 'e') {
            x = buf[0] - '0', y = buf[1] - '0';
            op = buf[2];
            if (op == 'i') input[x][y] = true;
            while (cin >> buf, buf[0] != '.') {
                int tx = buf[0] - '0', ty = buf[1] - '0';
                e[tx][ty].push_back(x * 10 + y);
            }
        }
        cin >> t;
        while (t--) {
            cin >> buf;
            cnt_i = 0, cnt_o = 0;
            memset(flag, false, sizeof flag);
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++)
                    if (input[i][j]) dfs(i, j);
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++)
                    if (value[i][j]) cout << "1";
                    else cout << "0";
            cout << endl;
        }
        if (n) cout << end