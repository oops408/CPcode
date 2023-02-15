#include <iostream>
using namespace std;
namespace first
{
	int y = 8;
}
namespace second
{
	double y = 2.1715;
}
int main() {
	// your code goes here
	int a;
	a = first :: y - second :: y;
	cout<<a;
	return 0;
}