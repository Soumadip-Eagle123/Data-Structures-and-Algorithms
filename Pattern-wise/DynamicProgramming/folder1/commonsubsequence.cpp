#include <bits/stdc++.h>
using namespace std;
int m, n;
char arr1[10010];
char arr2[10010];
int dp[101][101];

int rec(int i, int j){
    if(i==m || j==n){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 0;
    if(arr1[i]==arr2[j]) ans = 1+ rec(i+1, j+1);
    ans = max(ans, max(rec(i, j+1), rec(i+1, j)));
    return dp[i][j]=ans;
}
void solve(){
    cin >> m >> n;
    for(int i=0; i<m; i++){
        cin >> arr1[i];
    }
    for(int j=0; j<n; j++){
        cin >> arr2[j];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
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