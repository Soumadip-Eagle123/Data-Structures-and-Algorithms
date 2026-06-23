#include <bits/stdc++.h>
using namespace std;
int length;
int dp[101][101];

int rec(int L, int R){
    if(R-L == 1){
        return 0;
    }
    if(dp[L][R]!=-1) return dp[L][R];
    int cost = INT_MAX;
    for(int i= L+1; i<R; i++){
        cost = min(cost, R-L + rec(L, i) + rec(i, R));
    }
    return dp[L][R]=cost;
}
void solve(){
    cin >> length;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, length) << endl;
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