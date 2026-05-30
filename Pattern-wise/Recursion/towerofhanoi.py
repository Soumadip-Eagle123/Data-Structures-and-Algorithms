class Solution:
    def Helper(self, n, fromm, to, aux, count):
        if(n==0):
            return count
        count = self.Helper(n-1, fromm, aux, to, count)
        count+=1
        count = self.Helper(n-1, aux, to, fromm, count)
        return count
        
    def  towerOfHanoi(self, n, fromm, to, aux):
        return self.Helper(n, fromm, to, aux, 0)