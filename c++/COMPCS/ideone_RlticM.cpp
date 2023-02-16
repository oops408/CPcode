#include <iostream>
using namespace std;

#define LROUND(X) (int)(X+0.5f)

int main() {
	
	
	long A = 61; 
	long B = 30;
	
	
	cout << LROUND((A + A + A) * (1 + B * 0.01f));
	
	
	// your code goes here
	return 0;
}