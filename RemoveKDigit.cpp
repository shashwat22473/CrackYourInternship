#include <vector>
#include <string>

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> ans;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            while (!ans.empty() && (ans.back() - '0') > (num[i] - '0') && ans.size() + (n - i) > n - k) {
                ans.pop_back();
            }
            ans.push_back(num[i]);
        }
        string s;
        for (int i = 0; i < n-k; i++) {
            if (s.size() == 0 && ans[i] == '0') continue;
            s += ans[i];
        }

        if (s.size() == 0) return "0";
        return s;
    }
};
