#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
 
        vector<int> s(n);
        for(int i=0; i<n; i++)
            cin>>s[i];
 
        long long int ans=0;
        priority_queue<int> pq;
        for(int i=0; i<n; i++)
        {
            if(!pq.empty() && s[i]==0)
            {
                int x=pq.top();
                ans+=x;
                pq.pop();
            }
            else
                pq.push(s[i]);
        }
 
        cout<<ans<<endl;
    }
}
