#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main() {
	// your code goes here
	int ans = 0;
	string input1[10]
        = { "22", "121" };
	
	for(int i=0; i<2; i++){
		if(stoi(input1[i])%2==0 || stoi(input1[i]) == sqrt(stoi(input1[i]))){
			ans++;
		}
	}	
	cout<<ans;
	return 0;
}