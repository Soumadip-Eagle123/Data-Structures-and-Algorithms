class Solution:
    def Helper(self, n, zeros, ones, cout, ans):
        if ones + zeros == n:
            ans.append(cout)
            return
        self.Helper(n, zeros, ones + 1, cout + "1", ans)
        if zeros < ones:
            self.Helper(n, zeros + 1, ones, cout + "0", ans)

    def NBitBinary(self, n):
        ans = []
        self.Helper(n, 0, 0, "", ans)
        return ans
		