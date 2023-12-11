#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,mod=1e9+7;
long long ksm(long long a,long long b){
    long long res=1;
    a%=mod;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int n;
vector<pair<int,int>>tr[N];
int mp[N];
void solve(){
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int l,r,ll,rr;
        cin>>l>>r>>ll>>rr;
        tr[l].push_back({i,1});
        tr[ll].push_back({i,1});
        tr[r+1].push_back({i,-1});
        tr[rr+1].push_back({i,-1});
        v.push_back(l);v.push_back(ll);v.push_back(r+1);
        v.push_back(rr+1);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    long long ans=0;
    long long res=1,q=0;
    int cnt=0;
    long long inv=ksm(2,mod-2);
    for(int i:v){
        int f=0;
        for(auto &[x,y]:tr[i]){
            int t=mp[x];
            mp[x]+=y;
            if(y>0) f=1;
            else q=0;
            if(mp[x]==0){
                cnt--;
            }
            else if(mp[x]==1){
                if(t==0){
                  cnt++;
                }
                else {
                    res=res*inv%mod;
                }
            }
            else{
                res=res*2ll%mod;
            }
        }
        if(cnt==n&&f){
            ans=(ans+res-q+mod)%mod;
            q=res;
        }
    }
    cout<<ans<<'\n';
}
/*
3
1 4 1 4
1 4 1 4
1 4 1 4
*/

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
