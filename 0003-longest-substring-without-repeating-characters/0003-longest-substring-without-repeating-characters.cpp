class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int res = 0;

        for (int i = 0; i < n; i++) {
            vector<bool> vis(128, false);
            for (int j = i; j < n; j++) {
                if (vis[s[j]]) {
                    break;
                }
                else {
                    res = max(res, j - i + 1);
                    vis[s[j]] = true;
                }
            }
        }
        return res;
    }
};