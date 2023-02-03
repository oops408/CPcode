class Solution {
    static final String[] mapping = new String[] {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) return new ArrayList<>();
        List<String> res = new ArrayList<>();
        dfs(digits, 0, "", res);
        return res;
    }

    private void dfs(String digits, int idx, String cur, List<String> res) {
        if (idx == digits.length()) {
            res.add(cur);
            return;
        }
        int num = digits.charAt(idx) - '0';
        for (char c : mapping[num].toCharArray()) {
            dfs(digits, idx + 1, cur + c, res);
        }
    }
}
