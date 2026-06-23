#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[101][101];
int dp[101][101];
int done[101][101];
int rec(int idx, int idy){
    if(idx < 0 || idy < 0){
        return INT_MIN;
    }
    if(done[idy][idx]) return dp[idy][idx];
    if(idx==0 && idy==0){
        return arr[0][0];
    }
    int ans = arr[idy][idx]+max(rec(idx, idy-1), rec(idx-1, idy));
    done[idy][idx] = 1;
    return dp[idy][idx] = ans;
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    memset(done, 0, sizeof(done));
    cout << rec(n-1, m-1) << endl;
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