#include<bits/stdc++.h>
using namespace std;
void printKthMove(int discs, int src, int target, int helper, int k){
    if (k <= ((1<<(discs-1))-1)) printKthMove(discs-1, src, helper, target, k);
    else if(k==(1<<(discs-1))) cout << "Move from" << src << "To" << target << endl;
    else printKthMove(discs-1, helper, target, src, k - (1<<(discs-1)));
}
int main() {
    for(int i=0; i<=7; i++) printKthMove(3,1,3,2,i);
}