#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long
#define endl "\n"
#define nl "\n"
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define rev(p) reverse(p.begin(),p.end());
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define lb lower_bound
#define ub upper_bound

void solve(){
    ll n;
    cin>>n;
    ll a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    ll mn1=-1,mn2=-1;
    for(int i=0;i<n;i++){
        if(b[0]==a[i]&&mn1==-1){
            mn1=i;
        }
        if(b[1]==a[i]&&i!=mn1&&mn2==-1){
            mn2=i;
        }
    }
    ll ans=(a[mn1]+1)/2+(a[mn2]+1)/2;
    //c1
    for(int i=1;i<n;i++){
        ll as=0,p=a[i],q=a[i-1];
        ll as1=0;
        if(p<q){
            swap(p,q);
        }
        if(p>=q){
            if(2*q<=p){
                as+=q;
                p-=2*q;
                q=0;
                as+=(p+1)/2;
            }
            else{
                as+=(p+q)/3;
                if((p+q)%3!=0){
                    as++;
                }
            }
        }
        ans=min(ans,as+as1);
    }
    //c2
    for(int i=1;i<n-1;i++){
        ll as=0,p=a[i-1],q=a[i+1];
        if(p<q){
            swap(p,q);
        }
        as+=q;
        p-=q;
        as+=(p+1)/2;
        ans=min(ans,as);
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<":"<<" ";
        solve();
    }
    return 0;
}
/*
3
3 100 1
2

3
5 100 1
3

3
7 100 3
5

*/