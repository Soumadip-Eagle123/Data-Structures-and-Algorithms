#include <bits/stdc++.h>
using namespace std;
int n;
string t = "0100";
int dp[100100][5];

int rec(int level, int match){
    if(match==4){
        return 1;
    }
    if(level==n){
        return 0;
    }
    
    if(dp[level][match]!=-1){
        return dp[level][match];
    }
    int ans = 0;
    if(match==0){
        ans = rec(level+1, 1) + rec(level+1, 0);
    }
    else if(match==1){
        ans = rec(level+1, 1) + rec(level+1, 2);
    }
    else if(match==2){
        ans = rec(level+1, 3) + rec(level+1, 0);
    }
    else if(match==3){
        ans = rec(level+1, 4) + rec(level+1, 2);
    }
    
    return dp[level][match]=ans;
    
}
void solve(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
}
int main()
{
    solve();

    return 0;
}