from typing import List
class Solution:
    def Helper(self, nums, index, cout, ans):
        if index==len(nums):
            ans.append(cout)
            return
        self.Helper(nums, index+1, cout + [nums[index]], ans)
        while index+1<len(nums) and nums[index+1]==nums[index]:
            index+=1
        self.Helper(nums, index+1, cout, ans)
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        self.Helper(nums, 0, [], ans)
        return ans