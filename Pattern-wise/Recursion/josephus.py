from typing import List
class Solution:
    def Helper(self, n,  arr: List[int], k: int, starting: int) -> int:
        if n==1:
            return arr[0]
        rem = (starting+k-1)%n
        is_last = (rem == n-1)
        arr.pop(rem)
        new_starting = 0 if is_last else rem
        ans = self.Helper(n-1, arr, k, new_starting)
        return ans
    def findTheWinner(self, n: int, k: int) -> int:
        arr = []
        for i in range(1, n+1):
            arr.append(i)
        return self.Helper(n, arr, k, 0)