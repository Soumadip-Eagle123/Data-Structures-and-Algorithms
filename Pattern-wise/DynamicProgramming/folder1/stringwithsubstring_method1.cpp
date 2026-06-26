#include <bits/stdc++.h>
using namespace std;
int n;
string t = "0100";
int dp[100100][5];
int rec(int level, int lastthree){
    if(level==n){
        return 1;
    }
    if(dp[level][lastthree]!=-1){
        return dp[level][lastthree];
    }
   
    int ans = 0;
    
    if(level >= 3 && lastthree==2){
        ans = rec(level+1, 5);
    }
    else{
       ans = rec(level+1, ((lastthree<<1)|0)&7);
       ans += rec(level+1, ((lastthree<<1)|1)&7);
    }
    
    return dp[level][lastthree] = ans;
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