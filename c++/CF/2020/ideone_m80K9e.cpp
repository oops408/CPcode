#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[101][101], x[1001], k, n , res;
string s = "";
void Backtrack(int i , int j)
{
    if(i == n - 1 && j == n - 1)
    {
        cout << s << endl;
        res = 1;
    }
    if(i + 1 < n && a[i + 1][j])
    {
        a[i + 1][j] = 0;
        s += "D";
        Backtrack(i + 1, j);
        a[i + 1][j] = 1;
        s.pop_back();
    }
    if(j + 1 < n && a[i][j + 1])
    {
        a[i][j + 1] = 0;
        s += "R";
        Backtrack(i , j + 1);
        a[i][j + 1] = 1;
        s.pop_back();
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n ;j++)
        {
            cin >> a[i][j];
        }
    }
    Backtrack(0 , 0);
    if(res == 0) cout << -1;
}