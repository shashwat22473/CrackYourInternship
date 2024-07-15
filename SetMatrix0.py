class Solution(object):
    def setZeroes(self, matrix):
        m=len(matrix)
        n=len(matrix[0])
        l1=[]
        l2=[]
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==0:l1.append(i) ; l2.append(j)
        l1=set(l1);l2=set(l2)
        for i in l1:
            for j in range(n):
                matrix[i][j]=0
        for i in l2:
            for j in range(m):
                matrix[j][i]=0
        return matrix
