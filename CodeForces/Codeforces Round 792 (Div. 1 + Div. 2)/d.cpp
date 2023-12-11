#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int maxn=1e6;
ll a[maxn],b[maxn];
pii p[maxn];
ll n,k,ans;
void solve()
{
	cin>>n>>k;
	ans=0;
	for(int i=1;i<=n;i++)a[i]=b[i]=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].first;b[i]=p[i].first;
		p[i].first-=n-i;p[i].second=i;
	}
	sort(p+1,p+1+n,[&](pii a,pii b){return a.first>b.first;});
	for(int i=1;i<=k;i++)a[p[i].second]=1;
	for(int i=1,t=0;i<=n;i++){
		if(a[i]==1)t++;
		else ans+=t+b[i];
	}
	cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
    cin>>__;
//    __=1;
    while(__--)solve();
    return 0;
}