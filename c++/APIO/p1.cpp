#include <bits/stdc++.h>
using namespace std;
 
int main() {
int x = 11;
int d = 0;
int i =1;
vector<int>v{10,2,3,4,5};
for (; i<=5; i++){
   if ( v[i] < x){
        x = v[i];
        d=i;
 
}}
cout << d;
    return 0;
}
