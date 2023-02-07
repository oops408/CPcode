#include <iostream>

using namespace std;

int main() {
    int n, k, score, count = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> score;
        if (i >= k - 1) {
            if (score > 0) count++;
            else break;
        }
    }
    cout << count << endl;
    return 0;
}
