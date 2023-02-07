#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int n = s.length();
        vector<string> rows(min(numRows, n));
        int row = 0, step = 1;
        for (char c : s) {
            rows[row].push_back(c);
            if (row == 0) step = 1;
            else if (row == numRows - 1) step = -1;
            row += step;
        }
        string res;
        for (string row : rows) res += row;
        return res;
    }
};
