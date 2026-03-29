#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
int sum_of_digit(int num){
    int sum = 0;
    int temp = num;
    while(temp>0){
        sum += temp%10;
        temp/=10;
    }
    return sum;

}

void solve(){
  int N, S;
  cin >> N >> S;
  int lo=1;
  int hi=N;
  int ans = 0;
  while(lo<=hi){
    int mid=(lo+hi)/2;
    if(mid-sum_of_digit(mid)>=S ) hi = mid-1;
    else {
        ans = mid;
        lo = mid+1;
    }
  }
  cout << N - ans << endl;
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