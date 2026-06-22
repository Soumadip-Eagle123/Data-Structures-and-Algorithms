#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10010];
int dp[10010];
int rec(int level){
    if(level<0) return 0;
    if(dp[level]!=-1) return dp[level];
    int ans = 1;
    for(int prev_taken = 0; prev_taken<level; prev_taken++){
        if(arr[prev_taken]<arr[level]){
            ans = max(ans, 1+rec(prev_taken));
        }
    }
    return dp[level] = ans;
}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int best = 0
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++){
        best = max(best, rec(i));
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}