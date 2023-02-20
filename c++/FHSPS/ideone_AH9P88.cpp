#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool vi[1001],fc[1001];
vector<int>gp[10001];
vector<pair<int,int>>pv;
map<pair<int,int>,int>mp;
bool dfs(int node,int p,int b){
     vi[node]=1;
     
    for(int i=0;i<gp[node].size();i++){
        int n1=gp[node][i];
        if(!vi[n1]){
         dfs(n1,node,b);
        }
        else if(n1!=p){
        	fc[b]=1;
        	if(mp[{node,n1}]==0){
        	pv.push_back({node,n1}); 
        	mp[{node,n1}]=1;  mp[{n1,node}]=1;
        	}
        }
       
    }
  return 0;
}
int main() {
    
cin.tie(0)->sync_with_stdio(0);
int n,x,y;
cin>>n;

for(int i=1;i<n;i++){
    cin>>x>>y;
    gp[x].push_back(y);
    gp[y].push_back(x);

}

vector<int>load,load2;
for(int i=1;i<=n;i++)
   if(vi[i]==0){
     int g=dfs(i,-1,i);
     if(fc[i]==0)
     load.push_back(i);
     else load2.push_back(i);
   }
   
if(pv.size()==0){ cout<<0; return 0;}
//cout<<load.size()<<" "<<pv.size()<<" "<<"\n";
for(int i=0;i<load.size()-1;i++){
 // cout<<pv.back().first<<" "<<pv.back().second<<" ";
  //cout<<load[i]<<" "<<load[i+1]<<"\n";
//	pv.pop_back();
}
for(int i=0;i<load2.size();i++){
//	cout<<pv.back().first<<" "<<pv.back().second<<" ";
    cout<<load2[i]<<" ";//<<load2[i+1]<<"\n";
//	pv.pop_back();
}
    return 0;
}