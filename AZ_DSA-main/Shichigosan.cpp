#include<bits/stdc++.h>
using namespace std;
int n;
int ans = 0;
int num;

void rec(long long num, int three, int five, int seven){
   if(num>n) return;
   if(num <= n && three && five && seven) ans++;
   rec(10*num+3, 1, five, seven);
   rec(10*num+5, three, 1, seven);
   rec(10*num+7, three, five, 1);

}
int main(){
    cin >> n;
    rec(0,0,0,0);
    cout << ans << endl;
}