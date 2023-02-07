#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;
        int start = 0, max_len = 1;
        for (int i = 0; i < n;) {
            int j = i, k = i;
            while (k < n - 1 && s[k + 1] == s[k]) ++k; // Skip duplicates
            i = k + 1;
            while (j > 0 && k < n - 1 && s[j - 1] == s[k + 1]) {
                --j;
                ++k;
            }
            int len = k - j + 1;
            if (len > max_len) {
                start = j;
                max_len = len;
            }
        }
        return s.substr(start, max_len);
    }
};
