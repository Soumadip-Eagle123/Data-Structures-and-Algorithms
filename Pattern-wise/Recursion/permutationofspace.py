class Solution:

    def Helper(self, s, index, sout, ans):
        if index == len(s):
            ans.append(sout)
            return
        self.Helper(s, index + 1, sout + s[index], ans)
        if index < len(s) - 1:
            self.Helper(s, index + 1, sout + s[index] + " ", ans)

    def permutation(self, s):
        ans = []
        self.Helper(s, 0, "", ans)

        ans.sort()
        return ans