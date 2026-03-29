class Solution {
    long countTriplets(int n, int sum, long arr[]) {
        long count = 0;
        long inc = 0;
        long sum1=arr[0]+arr[1]+arr[2];
        Arrays.sort(arr);
        int i, j, k;
        for(i=0; i<n-2; i++){
            j = i+1;
            k = n-1;
            while(j<k){
                sum1 = arr[i]+arr[j]+arr[k];
                if(sum1<sum){
                    inc = (long)(k-j);
                    count+=inc;
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return count;
    }
}