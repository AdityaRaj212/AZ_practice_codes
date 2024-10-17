#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

/*
10
1 5 7 10 9 6 7 9 2 3
*/

void solve(){
    cin>>n;

    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> lis;
    vector<int> insertedAt(n,-1);
    vector<int> final_lis;

    for(int i=0;i<n;i++){
        if(lis.empty() || lis.back()<arr[i]){
            lis.push_back(arr[i]);
            insertedAt[i] = lis.size()-1;
        }else{
            auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
            *it = arr[i];
            insertedAt[i] = it-lis.begin();
        }
    }

    int curr = lis.size()-1;
    for(int i=n-1;i>=0;i--){
        if(insertedAt[i]==curr){
            final_lis.push_back(arr[i]);
            curr--;
        }
    }

    reverse(final_lis.begin(),final_lis.end());

    cout<<lis.size()<<endl;
    for(auto  v:final_lis){
        cout<<v<<", ";
    }
    cout<<endl;
}

signed main(){
    solve();
    return 0;
}