class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> triplets = new ArrayList<>();
        List<Integer> triplet = new ArrayList<>();
        for(int i=0; i<nums.length-2; i++){
            int j = i+1;
            int k = nums.length-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(j<k){
              if(nums[j]+nums[k]>(-1)*nums[i]) k--;
              else if(nums[j]+nums[k]<(-1)*nums[i]) j++;
              else {
                 triplet = Arrays.asList(nums[i], nums[j], nums[k]);
                 triplets.add(triplet);
                 while(j<k && nums[j+1]==nums[j]) j++;
                 while(j<k && nums[k]==nums[k-1]) k--;
                 j++;
                 k--;
              }
            }
        }
        return triplets;
    }
}