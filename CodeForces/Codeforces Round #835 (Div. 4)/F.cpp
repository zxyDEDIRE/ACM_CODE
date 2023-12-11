#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N=1e6+7;
const int INF=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
int n,c,d;
int a[N],su[N];
bool check(int k)
{
    // int sum=su[min(k+1,n)];
    // int num=c/sum;
    // int cc=c%sum;
    // int day=num*(k+1);
    // int dis=lower_bound(su,su+1+n,cc)-su;
    // if(cc==0){
    //     dis-=(k+1)-n;
    // }
    // // cout<<"dis="<<dis<<" "<<day<<" "<<cc<<" "<<sum<<endl;
    // return day+dis<=d;
    int res=0;
    for(int i=0;i<d;i++){
        res+=a[i%(k+1)+1];
    }
    return res>=c;
}
void solve()
{
    int maxx=0,summ=0;
    cin>>n>>c>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,[&](int a,int b){
        return a>b;
    });
    if(a[1]*d<c){
        cout<<"Impossible"<<endl;
        return;
    }
    for(int i=1;i<=min(d,n);i++){
        summ+=a[i];
    }
    if(summ>=c){
        cout<<"Infinity"<<endl;
        return;
    }
    for(int i=1;i<=d;i++)su[i]=0;
    for(int i=1;i<=n;i++)su[i]=su[i-1]+a[i];
    int l=0,r=1e8+7,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
        // cout<<l<<" "<<r<<endl;
    }
    cout<<ans<<endl;
    // cout<<check(4)<<endl;
}
signed main()
{
    //IOS
    int __=1;
    cin >> __;
    while (__--)
        solve();
}
//