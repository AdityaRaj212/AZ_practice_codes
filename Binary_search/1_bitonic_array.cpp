#include<bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

int n,q;
vector<int> arr;

void solve(){
    cin>>n>>q;

    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int peak = 1;
    int lo = 2;
    int hi = n;

    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(arr[mid]>arr[mid-1]){
            lo = mid + 1;
            peak = mid;
        }else{
            hi = mid - 1;
        }
    }
    // cout<<"Peak: "<<peak<<endl;

    while(q--){
        int k;
        cin>>k;

        vector<int> ans;    

        // first trip
        lo = 1;
        hi = peak;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid]==k){
                ans.push_back(mid);
                break;
            }else if(arr[mid]<k){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        // second trip
        lo = peak+1;
        hi = n;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid]==k){
                ans.push_back(mid);
                break;
            }else if(arr[mid]>k){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;

    while(T--){
        solve();
    }

    return 0;
}