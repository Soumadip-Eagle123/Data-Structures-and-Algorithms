#include<bits/stdc++.h>
using namespace std;
int n;
map<int,int> mp;
vector<int> b;
void rec(int l){
    if(l==n){
        for(int i=0; i<n; i++) cout << b[i] << " ";
        cout << endl;
        return;
    }
    for(auto &it:mp){
        if(it.second!=0){
            b.push_back(it.first);
            it.second--;
            rec(l+1);
            it.second++;
            b.pop_back();
        }
    }
}
int main(){
    cin >> n;
    int a;
    for(int i=0; i<n; i++){
        cin >> a;
        mp[a]++;
    }
    rec(0);
}