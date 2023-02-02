#include<bits/stdc++.h>
using namespace std;
const int N=1010;
bool is_prime[10010];
int n,k,mat[N][N],cnt,ans=1e9,x,y;
vector<int> prime;
void init()
{
    memset(is_prime,1,sizeof(is_prime));
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i<=10000;i++)
    {
        if(is_prime[i])
        {
            prime.push_back(i);
            for(int j=2;j*i<=10000;j++)
                is_prime[i*j]=0;
        }
    }
}
int main()
{
    init();
    cin>>n>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cnt=0;
            for(int p=0;p<prime.size();p++)
            {
                if(mat[i][j]>prime[p]) continue;
                int t=prime[p]-mat[i][j];
                if(t%k!=0) continue;
                int u=t/k;
                if(i-u>=0&&j-u>=0&&i+u<n&&j+u<n&&mat[i-u][j]+k*u==prime[p]&&mat[i+u][j]+k*u==prime[p]&&mat[i][j-u]+k*u==prime[p]&&mat[i][j+u]+k*u==prime[p])
                    cnt++;
                if(cnt>=5)
                {
                    if(ans>u)
                    {
                        ans=u;
                        x=i+1;
                        y=j+1;
                    }
                    break;
                }
            }
        }
    if(ans==1e9)
        cout<<"no"<<endl;
    else
        cout<<"yes"<<endl<<ans<<endl<<x<<" "<<y<<endl;
    return 0;
}
