class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for (int i = 0; i < order.size(); i++) {
            map[order[i]] = i;
        }
        for (int i = 1; i < words.size(); i++) {
            int j = 0;
            while (j < words[i - 1].size() && j < words[i].size() && words[i - 1][j] == words[i][j]) {
                j++;
            }
            if (j < words[i - 1].size() && j == words[i].size() || j < words[i - 1].size() && j < words[i].size() && map[words[i - 1][j]] > map[words[i][j]]) {
                return false;
            }
    }
    return true;
    }
};
