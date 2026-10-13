class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int st = 0, maxl = 1;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            int len = r - l - 1;
            if (len > maxl) {
                maxl = len;
                st = l + 1;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(st, maxl);
    }
};
