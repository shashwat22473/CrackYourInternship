class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        dp=[0 for i in range(len(t)+1)]
        dp[0]=1
        for i in range(len(s)):
            for j in range(len(t)-1,-1,-1):
                if (s[i]==t[j]):dp[j+1]+=dp[j]
        return dp[len(t)]
        
