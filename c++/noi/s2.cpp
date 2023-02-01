#include<iostream>
#include<cmath>
using namespace std;

int main() {
int pamela1, pamela2, pamela3;
cin >> pamela1 >> pamela2 >> pamela3;
int min_distance = abs(pamela1);
string name = "PAMELA I";
if(abs(pamela2) < min_distance) {
min_distance = abs(pamela2);
name = "PAMELA II";
}
if(abs(pamela3) < min_distance) {
min_distance = abs(pamela3);
name = "PAMELA III";
}
cout << name << endl;
return 0;
}
