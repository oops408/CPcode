#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int k,n,x[15];
vector<string>v;
void in(){
	for(int i=1;i<=k;i++) cout<<v[x[i]-1]<<' ';
	cout<<endl;
}
void Try(int i){
	for(int j=x[i-1]+1;j<=v.size()-k+i;j++){
		x[i]=j;
		if(i==k) in();
		else Try(i+1);
	}
}
int main(){
	cin>>n>>k;
	string x;
	set<string>se;
	for(int i=0;i<n;i++){
		cin>>x;
		se.insert(x);
	}
	
	for(auto s:se){
		v.push_back(s);
	}for(auto m:v) cout<<m<<' ';
	Try(1);
}