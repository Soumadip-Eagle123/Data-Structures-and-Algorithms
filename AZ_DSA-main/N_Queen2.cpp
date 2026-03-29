#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> queens;
int counter = 0;
/*
void printer(){
    // for(auto i: queens) cout << i << " ";
    // cout << endl;
    for(int i=0; i<queens.size(); i++){
        for(int j=0; j<queens.size(); j++){
            if(j==queens[i]) cout << "Q";
            else cout << "-";
        }
        cout << endl;
    }
}
    */
bool check(int row, int col){
    for(int prow= 0; prow<row; prow++){
        int pcol = queens[prow];
        if(col == pcol || abs(prow-row)==abs(pcol-col) || (abs(row-prow) == 1 && abs(col-pcol) == 2) || (abs(row-prow) == 2 && abs(col-pcol) == 1)) return false;
    }
    return true;
}
void rec(int level){
    if(level == n) {
        counter++;
        //printer();
        return;
    }
    for(int col = 0;col<n; col++){
        if (check(level, col)){
            queens.push_back(col);
            rec(level+1);
            queens.pop_back();
        }
    }

}

int main(){
    cin >> n;
    rec(0);
}