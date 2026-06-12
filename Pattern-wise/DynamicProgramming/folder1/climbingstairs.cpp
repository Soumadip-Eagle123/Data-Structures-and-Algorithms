class Solution {
public:
    int rec(int level, int n, int ans, int dp[]){
        if(level==n) return 1;
        if(level>n) return 0;
        if(dp[level]!=-1){
            return dp[level];
        }
        for(int i=1; i<=2; i++){
            if(level+i<=n) {
                int ways = rec(level+i, n, 0, dp);
                ans += ways;
            }
        }
        dp[level] = ans;
        return dp[level];
    }
    int climbStairs(int n) {
        int ans = 0;
        int dp[n];
        memset(dp, -1, sizeof(dp));
        return rec(0, n, ans, dp);
    }
};