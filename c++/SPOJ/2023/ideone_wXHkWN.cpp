#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    cout << "W";
    for (int i = 0; i < x; i++) {
        cout << "o";
    }
    cout << "w" << endl;
    return 0;
}