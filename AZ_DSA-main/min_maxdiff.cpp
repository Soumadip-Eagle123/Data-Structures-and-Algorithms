#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;  

bool check(int arr[], int x, int n, int k){
    int needed = 0;
    for(int i = 1; i < n; i++){
        needed += (arr[i] - arr[i-1] - 1) / x;  
    }
    return needed <= k;
}

void solve(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    int lo = 1, hi = 0;
    for(int i = 1; i < n; i++)
        hi = max(hi, arr[i] - arr[i-1]);

    int ans = hi;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(arr, mid, n, k)){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}