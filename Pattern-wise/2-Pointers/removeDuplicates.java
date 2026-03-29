class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0, j = 1, count = 1;
        if(nums.length==0) return 0;
        while (j < nums.length) {
            if (nums[j] == nums[j - 1])
                j++;
            else {
                nums[count++] = nums[j];
                i = j;
                j++;
            }
        }
        return count;
    }
}