#include<bits/stdc++.h>
using namespace std;
void mk(){ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
  void solve(){
int n,q;
cin>>n>>q;
vector<long long>v(n);
for(int i=0;i<n;i++){
  cin>>v[i];
}
while(q--){
  long long num;
  cin>>num;
  auto it=binary_search(v.begin(),v.end(),num);
  if(it){
    cout<<"Yes "<<lower_bound(v.begin(),v.end(),num)-v.begin()+1<<"\n";
  }
  else
  cout<<"No\n";
}
  }
int main(){mk();
int t=1;
//cin>>t;
while(t--)
solve();
}