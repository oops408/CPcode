#include<bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{
    if(n<=1)
        return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        for(int i=m;i<=n;i++)
        {
            if(is_prime(i))
                cout<<i<<endl;
        }
        cout<<endl;
    }
    return 0;
}
