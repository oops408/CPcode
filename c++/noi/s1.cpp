#include<iostream>
using namespace std;

int main() {
int t;
cin >> t;
while (t--) {
int n, m;
cin >> n >> m;
int a[n];
for (int i = 0; i < n; i++)
cin >> a[i];
for (int i = 0; i < m; i++) {
int l, r;
cin >> l >> r;
int sum = 0;
for (int j = l-1; j < r; j++)
sum += a[j];
cout << sum << " ";
}
cout << endl;
}
return 0;
}
