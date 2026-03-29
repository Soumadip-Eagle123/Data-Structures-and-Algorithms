class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int diff = Integer.MAX_VALUE;
        int ans=0;
        int sum=0;
        int i, j, k;
        for(i=0; i<nums.length-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            j=i+1;
            k=nums.length-1;
            while(j<k){
               sum = nums[i]+nums[j]+nums[k];
               if(sum-target>0){
                if(sum-target < diff) {
                    diff = sum-target;
                    ans = sum;
                }
                k--;
               }
               else if(sum-target < 0){
                 if(target-sum<diff){
                    diff = target-sum;
                    ans = sum;
                 }
                 j++;
               }
               else return sum;
            }
        }
        return ans;
    }
}