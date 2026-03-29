class Solution {
    public int removeDuplicates(int[] nums) {
        int i=0, j=1;
        int index=0;
        int count = 1;
        while(j<nums.length){
            if(nums[j]==nums[j-1]){
                count++;
            }
            else{
                if(count>1){
                    nums[index++] = nums[i];
                    nums[index++] = nums[i];
                    count=1;
                }
                else{
                    nums[index++] = nums[i];
                }
                i = j;
            }
            j++;
        }
        if(count>1){
            nums[index++] = nums[i];
            nums[index] = nums[i];
        }
        else nums[index] = nums[i];
        return index+1;
    }
}