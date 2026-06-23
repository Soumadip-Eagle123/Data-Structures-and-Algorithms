#include <bits/stdc++.h>
using namespace std;
int x;
int dp[10010];

int rec(int x){
    if(x==0){
        return 0;
    }
    if(dp[x]!=-1) return dp[x];
    int ans = 0;
    for(int m=0; (1<<m)<x; m++){
        if(rec(x-(1<<m))==0) ans = 1;
    }
    return dp[L][R]=ans;
}
void solve(){
    cin >> x;
    memset(dp, -1, sizeof(dp));
    cout << rec(x) << endl;
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