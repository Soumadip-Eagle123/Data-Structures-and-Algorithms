#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v;
const int MOD = 1e9+7;
int check(int mid, vector<int>v, int n){
    if(v[mid]<= v[n-1]) return 1;
    else return 0;
}
void solve(){
 int n; cin >> n;
 v.resize(n);
 for(int i=0; i<n; i++){
    cin >> v[i];
 }
 int lo=0;
 int hi = n-1;
 int ans = -1;
 while(lo<=hi){
    int mid = lo +(hi-lo)/2;
    if(check(mid, v, n)) {
        ans = mid;
        hi = mid-1;
    }
    else lo = mid+1;
 }
 cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t; 
    while(t--){
    solve();
    }
    return 0;
}