from typing import List
class Solution:
    def Helper(self, s, index, cout, ans) -> None:
        if(index==len(s)):
            ans.append(cout)
            return
        self.Helper(s, index+1, cout+s[index], ans)
        if(s[index].isalpha()):
            alpha = s[index].lower() if s[index].isupper() else s[index].upper()
            self.Helper(s, index+1, cout+alpha, ans)
        
    def letterCasePermutation(self, s: str) -> List[str]:
        ans = []
        self.Helper(s, 0, "", ans)
        return ans