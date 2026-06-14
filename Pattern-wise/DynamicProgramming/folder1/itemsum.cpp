#include <bits/stdc++.h>
using namespace std;

int n, t;
int x[n];

int dp[105][10100];
int rec(int level, int sum_left){
    if(sum_left<0){
        return 0;
    }
    
    if(level==n+1) {
        if(sum_left==0){
            return 1;
        }
    }else{
        return 0;
    }
    if(dp[level][sum_left]!=-1){
        return dp[level][sum_left];
    }
    
    int ans = 0;
    if(rec(level+1, sum_left)==1){
        ans = 1;
    }
    else if(rec(level+1, sum_left-x[level])){
        ans = 1;
    }
    return dp[level][sum_left]=ans;
    
}

void printset(int level, int sum_left){
    cout << "printer: " << level << "left: " << left << endl;
    if(level==n+1){
        return;
    }
    //find the correct transition
     if(rec(level+1, sum_left)==1){
        printset(level+1, sum_left);
    }
    else if(rec(level+1, sum_left-x[level])){
        cout << x[level] << " ";
        printset(level+1, sum_left-x[level])
    }
}

void solve(){
    cin >> n;
    int q;
    cin >> q;
    for(int i=1; i<=n;i++){
        cin >> x[i];
    }
    memset(dp, -1, sizeof(dp));
    while(q--){
        cin >> t;
        if(rec(1, t){
            printset(1, t);
            cout << endl;
        })
        else{
            cout << "no solution";
        }
    }
}

int main()
{
    
    return solve()

    return 0;
}