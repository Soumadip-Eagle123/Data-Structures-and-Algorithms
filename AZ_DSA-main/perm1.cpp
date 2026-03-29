#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;
int inf = 1e9+7;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    do{
        for(int u: nums) cout << u << " ";
        cout << endl;
    }while(next_permutation(nums.begin(), nums.end()));
}