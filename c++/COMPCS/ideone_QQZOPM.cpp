#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	int arr[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		
	}
		for(int i=0;i<n;i++){
		if(arr[i-1]!=arr[i]){sum++;}
		
		
	}
	cout<<sum;
	return 0;
} 