#include<bits/stdc++.h>
using namespace std;

int n;
int x,k;
vector<int> time_req;
vector<int> skill;
vector<bool> taken;

bool check(int level){
    int time_taken = 0;
    int item_taken = 0;

    for(int i=0;i<level;i++){
        if(taken[i]){
            time_taken += time_req[i];
            item_taken++;
        }
    }

    time_taken += time_req[level];
    item_taken++;

    if(time_taken<=x && item_taken<=k){
        return true;
    }
    return false;
}

int rec(int level){
    // base case
    if(level==n){
        return 0;
    }

    // case 1 : don't take
    int ans = rec(level+1);

    // case 2 : take
    if(check(level)){
        taken[level] = true;
        ans = max(ans,skill[level]+rec(level+1));
        taken[level] = false;
    }

    return ans;    
}

void solve(){
    cin>>n>>x>>k;

    time_req.resize(n);
    skill.resize(n);
    for(int i=0;i<n;i++){
        cin>>time_req[i]>>skill[i];
    }

    cout<<rec(0)<<endl;
}

signed main(){
    solve();
    return 0;
}