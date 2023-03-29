using namespace std;
 
#define inf 0x3f3f3f3f
#define sz(x) int((x).size())
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
 
template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
 
const int MAXN = 100005;
 
int prv[MAXN], nxt[MAXN];
int pos[MAXN], tmp[MAXN], val[MAXN];
 
#ifdef Nhoksocqt1
 
vector<int> sendedMessage;
 
void Send(int x) {
    sendedMessage.push_back(x);
}
 
void Remove(int d) {
    cout << "REMOVE AT POS: " << d << '\n';
}
 
#endif // Nhoksocqt1
 
void Anna(int n, vector<char> S) {
    for (int i = 0; i < n; ++i) {
        int val = (S[i] != 'X') ? 1 + (S[i] == 'Z') : 0;
        Send(val >> 1 & 1);
        Send(val & 1);
    }
}
 
void Bruno(int N, int L, vector<int> A) {
    for (int i = 0; i < N; ++i)
        val[i] = (A[2 * i] << 1) | A[2 * i + 1];
 
    int l(0), r(N - 1);
    while(l <= r && val[l] != 0) {
        Remove(l);
        ++l;
    }
 
    while(r >= l && val[r] != 2) {
        Remove(r);
        --r;
    }
 
    if(l >= r)
        return;
 
    int nArr(0);
    for (int i = l; i <= r; ++i) {
        while(i < r && val[i] == val[i + 1]) {
            Remove(i);
            ++i;
        }
 
        pos[++nArr] = i;
    }
 
    int n(0);
    for (int i = 1; i <= nArr; ++i) {
        if(val[pos[i]] == 1 || i == nArr || val[pos[i + 1]] == 1) {
            tmp[++n] = pos[i];
        } else {
            // val[pos[i + 1]] = 2 - val[pos[i]]
            int j(i + 1);
            while(j <= nArr && val[pos[j]] != 1)
                ++j;
 
            int posX = (val[pos[i]] == 0 ? pos[i] : pos[i + 1]);
            int posZ = (val[pos[i]] == 0 ? pos[i + 1] : pos[i]);
            tmp[++n] = (i == 1) ? posX : posZ;
            for (int k = i; k < j; ++k) {
                if(tmp[n] != pos[k])
                    Remove(pos[k]);
            }
 
            i = j - 1;
        }
    }
 
    nArr = n;
    for (int i = 0; i <= nArr; ++i) {
        pos[i] = tmp[i];
        prv[i + 1] = i;
        nxt[i] = i + 1;
        //cout << pos[i] << " \n"[i == nArr];
    }
 
    nxt[nArr] = 0;
    int CNT(0);
    for (int i = 1; i > 0; i = nxt[i]) {
        if(prv[i] > 0 && nxt[i] > 0) {
            if(val[pos[prv[i]]] == 0 && val[pos[i]] == 1 && val[pos[nxt[i]]] == 2) {
                ++CNT;
                Remove(pos[i]);
                prv[nxt[i]] = prv[i];
                nxt[prv[i]] = nxt[i];
 
                int j(prv[i]);
                if(prv[prv[j]] > 0 && val[pos[prv[prv[j]]]] == 0) {
                    while(prv[prv[j]] > 0 && val[pos[prv[prv[j]]]] == 0) {
                        ++CNT;
                        Remove(pos[j]);
                        prv[nxt[j]] = prv[j];
                        nxt[prv[j]] = nxt[j];
                        j = prv[j];
 
                        Remove(pos[j]);
                        prv[nxt[j]] = prv[j];
                        nxt[prv[j]] = nxt[j];
                        j = prv[j];
                    }
                }
 
                j = nxt[i];
                int tmp(j);
                if(nxt[j] > 0 && nxt[nxt[j]] > 0 && val[pos[nxt[nxt[j]]]] == 2) {
                    while(nxt[j] > 0 && nxt[nxt[j]] > 0 && val[pos[nxt[nxt[j]]]] == 2) {
                        ++CNT;
                        Remove(pos[j]);
                        prv[nxt[j]] = prv[j];
                        nxt[prv[j]] = nxt[j];
                        j = nxt[j];
 
                        Remove(pos[j]);
                        prv[nxt[j]] = prv[j];
                        nxt[prv[j]] = nxt[j];
                        j = nxt[j];
                    }
                }
 
                Remove(pos[j]);
                prv[nxt[j]] = prv[j];
                nxt[prv[j]] = nxt[j];
                j = nxt[j];
 
                i = prv[j];
            }
        }
    }
 
    //int cntNow(0); for (int i = l; i <= r; ++i) cntNow += ((i == l || val[i - 1] != val[i]) && val[i] == 1);
    //cout << "COUNT PAIRS: " << CNT << " ANS: " << cntNow << '\n';
 
    for (int i = nxt[0]; i > 0; i = nxt[i])
        Remove(pos[i]);
}
