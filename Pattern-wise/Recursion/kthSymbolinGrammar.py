class Solution(object):
    def helper(self, n, k, curr):
        if n==1:
            return curr
        if(k> pow(2, n-2)):
            k = k - pow(2, n-2)
            curr=0 if curr == 1 else 1
        return self.helper(n-1, k, curr)
    def kthGrammar(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        ans = self.helper(n, k, 0)
        return 0 if ans == 0 else 1