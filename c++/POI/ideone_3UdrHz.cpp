#include<bits/stdc++.h>
using namespace std;

const int maxQ=2e5;
struct ARR{
	int a,b;
	bool operator<(const ARR rhs)const{
		return (a!=rhs.a)?a<rhs.a: b<rhs.b;}
	bool operator==(const ARR rhs)const{
		return a==rhs.a and b==rhs.b;}
}org[maxQ],arr[maxQ];
int T[maxQ], on[maxQ];

int main(){
	int N, Q;
	cin>>N>>Q;
	for(int i=0; i<Q; i++){
		cin>>T[i]>>org[i].a>>org[i].b;
		arr[i].a=org[i].a;
		arr[i].b=org[i].b;
	}
	sort(arr,arr+Q);
	int uQ=unique(arr,arr+Q)-arr;
	
	for(int i=0; i<Q; i++){
		int p=lower_bound(arr,arr+uQ,org[i])-arr;
		if(T[i]==1)
		 on[p]=1;
		else if(T[i]==2)
		 on[p]=0;
		else{
			if(on[p]==0){
				cout<<"No\n";
				continue;
			}
			swap(org[i].a, org[i].b);
			p=lower_bound(arr,arr+uQ,org[i])-arr;
			if(p<uQ and arr[p]==org[i] and on[p]==1)
			 cout<<"Yes\n";
			else 
			 cout<<"No\n";
		}
	}
	return 0;
}