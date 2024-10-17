#include<bits/stdc++.h>
using namespace std;

int n;
int queens[10];

void printer(){
    cout<<"Queens: ";
    for(int i=0;i<n;i++){
        cout<<queens[i]<<" ";
    }
    cout<<endl;
}

bool check(int row,int col){
    for(int pr=0;pr<row;pr++){
        int pc = queens[pr];
        if((col==pc) || (abs(pr-row)==abs(pc-col))){
            return 0;
        }
    }
    return 1;
}

int rec(int level){
    //base case
    cout<<"Level: "<<level<<endl;
    printer();
    if(level==n){
        return 1;
    }    

    //recursive case
    int ans = 0;
    for(int ch=0;ch<n;ch++){
        cout<<"Trying choice "<<ch<<" at level "<<level<<endl;
        if(check(level,ch)){
            cout<<"Valid choice "<<ch<<" at level "<<level<<endl;
            queens[level] = ch;
            ans += rec(level+1);
            queens[level] = -1;
        }
    }
    return ans;
}

void solve(){
    cin>>n;
    memset(queens,-1,sizeof(queens));
    cout<<rec(0)<<"\n";
}

int main(){
    solve();
    return 0;
}