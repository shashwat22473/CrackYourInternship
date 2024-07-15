class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(needle)
        z =len(haystack)
        x =0
        y=n
        count =0
        for i in range(z-n+1):
            if haystack[x:y] == needle:
                count+=1
                break
            else:
                x+=1
                y+=1
        if count ==0:
            return(-1)
        elif count==1:
            return(x)
