class Solution {
public:
    double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    double res = 1.0;
    long long p = abs((long long) n);
    while (p > 0) {
        if (p % 2 == 1) {
            res *= x;
        }
        x *= x;
        p /= 2;
    }
    if (n < 0) {
        return 1.0 / res;
    } else {
        return res;
    }
}
};
