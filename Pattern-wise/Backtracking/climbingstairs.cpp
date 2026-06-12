class Solution {
public:
    int rec(int level, int n, int ans){
        if(level==n) return 1;
        if(level>n) return 0;

        for(int i=1; i<=2; i++){
            if(level+i<=n) {
                int ways = rec(level+i, n, 0);
                ans += ways;
            }
        }
        return ans;
    }
    int climbStairs(int n) {
        int ans = 0;
        return rec(0, n, ans);
    }
};