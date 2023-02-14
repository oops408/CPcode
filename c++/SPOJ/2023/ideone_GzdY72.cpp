#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >>n ;
	int maxx,maxy,miny, minx;
	maxx = maxy = int(-1e9);
	miny = minx = (int)1e9;
	for(int i = 0; i < n; i++){
		int x,y;
		cin >> x >>y;
		maxx = max(maxx, x);
		minx = min(minx, x);
		maxy = max(maxy, y);
		miny = min(miny, y);
	}
	cout << minx << ' ' << miny << ' ' << maxx << ' ' << maxy;
	return 0;
}