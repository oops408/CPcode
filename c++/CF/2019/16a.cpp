#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	char arr[105][105];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			if(arr[i][j]!=arr[i][j+1]){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j][i]==arr[j+1][i]){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
