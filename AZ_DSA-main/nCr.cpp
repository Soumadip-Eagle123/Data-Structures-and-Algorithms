
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;
ll binpow(ll base, ll pow, ll mod){
if(pow==0) return 1;
if(pow%2==0) return binpow((base*base)%mod, pow/2, mod)%mod;
else return (base * (binpow(base, pow-1, mod))%mod)%mod;
}
ll inv(ll x){
    return binpow(x%MOD, MOD-2, MOD);
}
ll fact(ll x){
    if(x==0) return 1;
    else return ((x%MOD)*fact(x-1))%MOD;
}
ll nCr(ll n, ll r){
    ll num = fact(n);
    ll den = (fact(r) * fact(n - r)) % MOD;
    return (num * inv(den)) % MOD;
}
int main(){
  int n, r;
  cin >> n >> r;
  cout << nCr(n,r);
}

