from typing import List
class Solution:
    def Helper(self, n, depth, right, left, cout, ans) -> None:
        if right==left:
            if right==n:
                ans.append(cout)
                return
            self.Helper(n, depth+1, right+1, left, cout+"(", ans)

        elif right>left:
            if right<n:
                self.Helper(n, depth+1, right+1, left, cout+"(", ans)
            self.Helper(n, depth, right, left+1, cout+")", ans)
    def generateParenthesis(self, n: int) -> List[str]:
         ans = []
         self.Helper(n, 0, 0, 0, "", ans)
         return ans