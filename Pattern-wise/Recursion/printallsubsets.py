from typing import List
class Solution:
    def solve(self, ip: List[int], op: List[int], result: List[List[int]]) -> None:
        if(len(ip)==0):
            result.append(op)
            return result
        op1 = op.copy()
        op.append(ip[0])
        op2 = op.copy()
        result = self.solve(ip[1:], op1, result)
        result = self.solve(ip[1:], op2, result)
        return result

       
    def subsets(self, nums: List[int]) -> List[List[int]]:
       return self.solve(nums, [], [])