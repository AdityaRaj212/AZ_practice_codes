#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> queen;
vector<vector<string>> ans;

bool check(int row, int col){
    for(int pr=0; pr<row; pr++){
        int pc = queen[pr];
        if((pc==col) || (abs(pr-row)==abs(pc-col)!=0)){
            return false;
        }
    }
    return true;
}

int rec(int level){
    if(level==n){
        vector<string> state;
        for(int i=0;i<n;i++){
            string str = "";
            for(int j=0;j<n;j++){
                if(queen[i]==j){
                    str.push_back('Q');
                }else{
                    str.push_back('.');
                }
            }
            state.push_back(str);
        }
        ans.push_back(state);
        return 1;
    }

    int ans = 0;

    for(int ch=0;ch<n;ch++){
        if(check(level, ch)){
            queen[level] = ch;
            ans += rec(level+1);
            queen[level] = -1;
        }
    }

    return ans;
}

void print(){
    for(auto v: ans){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<v[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

void solve(){
    cin>>n;
    queen.assign(n, -1);
    cout<<rec(0)<<endl;
    print();
}

signed main(){
    solve();
    return 0;
}