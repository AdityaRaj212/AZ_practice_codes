#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100100];
vector<int> permutation;

void rec(int level){
    if(level==n){
        for(int i=0;i<permutation.size();i++){
            cout<<permutation[i]<<" ";
        }
        cout<<endl;
        return;
    }
    rec(level+1);
    permutation.push_back(arr[level]);
    rec(level+1);
    permutation.pop_back();
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    rec(0);
}

int main(){
    solve();
    return 0;
}