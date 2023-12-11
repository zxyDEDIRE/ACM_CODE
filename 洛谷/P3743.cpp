#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int a[maxn],b[maxn];
int n,p;
bool check(long double x){
	long double s=0,t=0,T=1.0;
	for(int i=1;i<=n;i++)
	{
		s+=x*a[i];
		t+=min(x*a[i],T*b[i]);
	}
	t+=p*x;
	if(t<s)return 0;
	return 1;
}
void solve()
{
	cin>>n>>p;
	int s=0,t=0;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i],s+=a[i],t+=b[i];
	if(p>=s){
		cout<<-1<<endl;
		return ;
	}
	long double l=0,r=1e12,ans=0;
	while(r-l>0.00001)
	{
		long double mid=0.5*(r+l);
		if(check(mid))ans=l,l=mid;
		else r=mid;
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
//    cin>>__;
    __=1;
    while(__--)solve();
    return 0;
}
/*
3 5
4 3
5 2
6 1
15 6
*/