#include <bits/stdc++.h>
using namespace std;
void minimumind(vector<string>l1,vector<string>l2){
	int val;int mini=INT_MAX;int n1,n2;
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			if(l1[i]==l2[j]){
				val=i+j;
				if(val<mini)
					mini=val;
					cout<<val;
			}
		}
	break;	
	}
// return mini;	
}
int main() {
	int n1,n2;cin>>n1>>n2;
	vector<string>l1(n1);
	vector<string>l2(n2);
	for(int i=0;i<n1;i++)cin>>l1[i];
	for(int i=0;i<n2;i++)cin>>l2[i];
	minimumind(l1,l2);
	// your code goes here
	return 0;
}