#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int maxn=1e6;
pii a[maxn];
ll x[maxn];
int p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>a[i].first;
	for(int i=1;i<=k;i++)
		cin>>a[i].second;
	sort(a+1,a+1+k,[&](pii a,pii b){return a.first<b.first;});
	a[0].first=0;a[n+1].first=n+1;
	a[n+1].second=a[0].second=2e10;
	for(int i=1;i<=k;i++)
	{
		ll t=min(a[i-1].second+abs(a[i-1].first-i),a[i+1].second+abs(a[i+1].first-i) );
		a[i].second=min(a[i].second,t);
	}
	int l=1;
	for(int i=1;i<=n;i++)
	{
		while(l<=n&&a[l].first<i)l++;
		p[i]=min(a[l-1].second+abs(a[l-1].first-i),a[l].second+abs(a[l+1].first-i));
		cout<<p[i]<<" ";
	}
	cout<<endl;
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