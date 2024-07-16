class Solution(object):
    def addBinary(self, a, b):
        tt=0;ti=0
        f=len(a);f_=len(b)
        for i in range(-1,-f-1,-1):tt+=int(a[i])*(2**(-(i+1)))
        for i in range(-1,-f_-1,-1):ti+=int(b[i])*(2**(-(i+1)))
        print(tt)
        print(ti)
        tt+=ti
        x=bin(tt)[2:]
        return x
