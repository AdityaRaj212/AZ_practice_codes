#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[10101];
int dp[10101];

struct monotone_deque{
    deque<int> dq;

    void insert(int x){
        while(!dq.empty() && dq.back()>x){
            dq.pop_back();
        }
        dq.push_back(x);
    }

    void erase(int x){
        if(dq.front()==x){
            dq.pop_front();
        }
    }

    int getmin(){
        return dq.front();
    }
};

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    monotone_deque mt;

    dp[0] = arr[0];

    for(int i=1;i<n;i++){
        mt.insert(dp[i-1]);
        if(i-k-1>=0){
            mt.erase(dp[i-k-1]);
        }
        dp[i] = mt.getmin() + arr[i];
    }

    cout<<dp[n-1]<<endl;
}

signed main(){
    solve();
    return 0;
}