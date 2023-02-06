#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,q,head[N],tot,vis[N],dfn[N],low[N],cnt,sta[N],top,c[N];
long long a[N],ans[N];
struct node{
int to,nxt;
}edge[N<<1];
inline void add(int u,int v){
edge[++tot].to=v;
edge[tot].nxt=head[u];
head[u]=tot;
}
void tarjan(int u){
dfn[u]=low[u]=++cnt;
vis[u]=1;
sta[++top]=u;
for(int i=head[u];i;i=edge[i].nxt){
int v=edge[i].to;
if(!dfn[v]){
tarjan(v);
low[u]=min(low[u],low[v]);
}
else if(vis[v])
low[u]=min(low[u],dfn[v]);
}
if(dfn[u]==low[u]){
++cnt;
while(sta[top]!=u){
vis[sta[top]]=0;
c[sta[top--]]=cnt;
}
vis[sta[top]]=0;
c[sta[top--]]=cnt;
}
}
inline void modify(int p,int x){
a[p]+=x;
}
inline long long query(int u,int v){
long long sum=0;
while(c[u]!=c[v]){
if(dfn[c[u]]<dfn[c[v]])
sum+=a[u],u=c[u];
else
sum+=a[v],v=c[v];
}
if(dfn[u]>dfn[v])
swap(u,v);
return sum+a[u]+a[v];
}
int main(){
cin>>n>>q;
for(int i=1;i<=n;i++)
cin>>a[i];
int u,v;
for(int i=1;i<n;i++){
cin>>u>>v;
add(u,v);
add(v,u);
}
tarjan(1);
int opt,x,y;
while(q--){
cin>>opt;
if(opt==0){
cin>>u>>v>>x>>y;
modify(u,-1);
modify(v,-1);
add(x,y);
add(y,x);
tarjan(x);
}
else if(opt==1){
cin>>x>>y;
modify(x,y);
}
else{
cin>>x>>y;
cout<<query(x,y)
  }
  
  return 0;
}
