#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n,a[12][12],check;
string s;

void Try(int i,int j){
	if(i==n-1&&j==n-1){
		cout<<s<<' ';
		check=1;
		return;
	}
	if(a[i+1][j]){
		s+="D";
		Try(i+1,j);
		s.pop_back();
	}
	if(a[i][j+1]){
		s+="R";
		Try(i,j+1);
		s.pop_back();
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		if(!a[0][0]) cout<<"-1";
		else {
			Try(0,0);
			if(!check) cout<<"-1";
		}
		cout<<endl;
	}
}