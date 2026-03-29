#include<iostream>
using namespace std;
int bin_pow(int base, int pow){
  int ans = 1;
  if(pow==0) return ans;
  else if(pow%2==1){
    ans *= base;
    pow--;
  }
  else{
    base = base*base;
    pow /= 2;
  }
}
int amodb(int x, int y){
  if(x%y==0) return 1;
  else return y-x%y+1;
}
void solve(){
  int k; cin >> k;
  int ans;
  int digit = 1;
  while(k>0){
    k -= 9*digit*bin_pow(10, digit-1);
    digit++;
  }
  if(amodb(k,digit)==digit) {
    ans = ((k/digit)/bin_pow(10,amodb(k,digit)-1))%10+1;
  }
  else{
    ans = ((k/digit)/bin_pow(10,amodb(k,digit)-1))%10;
  }
  cout << ans << endl;
}
int main(){
  int q; cin >> q;
  while(q--){
    solve();
  }
}