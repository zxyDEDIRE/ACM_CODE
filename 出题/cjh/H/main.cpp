/*
滑铲xiu~
*/
#include<bits/stdc++.h>
using namespace std;
using ll=__int128;
ll Lcm(ll c,ll x){
    if(!c) return x;
    return c/__gcd(x,c)*x;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){
        x=1;y=0;
        return a;
    }
    ll x1,y1,d;
    d=exgcd(b,a%b,x1,y1);
    x=y1;y=x1-a/b*y1;
    return d;
}
const int N=25;
ll pr[N];
int cnt[N];
int top;
ll ans;
ll res[3];
void dfs(int id){
    if(id==top){
        ll x,y;
        exgcd(res[0],res[1],x,y);
        ll k1=-x/res[1],k2=y/res[0];
        while(x+res[1]*k1>=0) k1--;
        while(y-res[0]*k2<=0) k2--;
        k1=min(k1,k2);
        ll c=res[0]*(-x)+y*res[1];
        ll a=2ll*res[0]*res[1],b=res[2];
        ll x1,y1;
        ll d=exgcd(b,a,x1,y1);
        if(c%d) return;
        x1*=c/d;y1*=c/d;
        ll b1=b/d,a1=a/d;
        ll k3=-x1/a1;
        ll k4=(y1-k1)/b1;
        while(y1-k4*b1>k1) k4++;
        while(x1+k3*a1<=0) k3++;
        k1=y1-max(k4,k3)*b1;
        ans=min(ans,-(x+res[1]*k1)*res[0]);
        return;
    }
    for(int i=0;i<3;i++)
    {
        res[i]=res[i]*pr[id];
        dfs(id+1);
        res[i]=res[i]/pr[id];
    }
}
void Pr(ll ans){
    if(ans>=10) Pr(ans/10);
    cout<<char('0'+ans%10);
}
long long x[N];
void solve(){
    int n;
    cin>>n;
    ll lc=0;
    // lc=rand()%20000000+1;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        lc=Lcm(lc,x[i]);
    }
   
    top=0;
    lc*=6;
    ans=lc;
    for(int i=2;1ll*i*i<=lc;i++){
        if(lc%i==0){
            pr[top]=1;
            cnt[top]=0;
            while(lc%i==0){
                lc/=i;cnt[top]++;
                pr[top]*=i;
            }
            top++;
        }
    }
    if(lc>1){
        pr[top]=lc;
        cnt[top]=1;
        top++;
    }
    res[0]=res[1]=res[2]=1;
    dfs(0);
    // ll lcc=lc;
    // ll sum=0;
    // for(int i=1;;i++){
    //     sum+=1ll*i*i;
    //     if(sum%lcc==0){
    //         cout<<i<<'\n';
    //         break;
    //     }
    // }
    Pr(ans);cout<<'\n';
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*
11
2 3 5 7 11 13 17 19 23 29 31
1390752
*/