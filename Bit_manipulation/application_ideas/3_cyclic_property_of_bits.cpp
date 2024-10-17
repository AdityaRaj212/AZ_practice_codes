#include<bits/stdc++.h>
using namespace std;
using lli = long long;

string getbitstr(int x){
    string cur="";
    while(x){
        if(x%2){
            cur += '1';
        }else{
            cur+= '0';
        }
        x/=2;
    }

    reverse(cur.begin(), cur.end());
    return cur;
}

lli sum_of_bits(lli x){
    lli ans = 0;
    lli tot = x+1;
    for(int i=0;i<60;i++){
        lli full = (tot/(1LL<<(i+1)));
        lli left = tot%(1LL<<(i+1));
        lli extra = max(left-(1LL<<i),0LL);
        ans += full*(1LL<<i)+extra;
    }
    return ans;
}

lli find_kth_one(lli k){
    int lo = 0, hi = k, ans = -1;

    while(lo<=hi){
        lli mid = (lo+hi)/2;
        if(sum_of_bits(mid)>=k){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }

    return ans;
}

int get_kth_one_pos_in_num(int x, int k){
    int cnt = 0;
    string num = getbitstr(x);

    for(int i=0;i<num.size();i++){
        if(num[i]=='1'){
            cnt++;
        }
        if(cnt==k){
            return i;
        }
    }
}

lli total_bits_till(lli x){
    lli ans = 0;
    lli len = 1;
    lli num = 1;
    while(num<=x){
        lli sametill = num*2 - 1;
        if(sametill<=x){
            ans += len*(sametill-num+1);
            num += sametill+1;
            len++;
        }else{
            ans += len*(x-num+1);
            break;
        }
    }

    return ans+1;
}

void solve(){
    lli q;
    cin>>q;

    while(q--){
        lli k;
        cin>>k;

        lli num = find_kth_one(k);
        lli pos_in_num = k - sum_of_bits(num-1);
        lli index = get_kth_one_pos_in_num(num, pos_in_num);
        cout<<total_bits_till(num-1)+index<<endl;
    }
}

signed main(){
    solve();
    return 0;
}