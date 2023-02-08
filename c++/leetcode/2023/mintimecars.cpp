class Solution {
public:
    int minimumTime(string s) {
        int n = s.size(), left = 0, res = n;
        for (int i=0; i < n; ++i) {
            left = min(left + (s[i] - '0') * 2, i+1);
            res = min(res, left + n - 1 - i);
        }
        return res;
    }
};
