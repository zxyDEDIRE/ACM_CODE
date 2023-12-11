#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int a[maxn];
int p[maxn];
int t[maxn];
int n,k,ans,ma,mi;
void solve()
{
	cin>>n>>k;
	ma=-maxn;
	mi=maxn;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		ma=max(ma,p[i]);
		mi=min(mi,p[i]);
		if(i!=0)ans+=abs(p[i]-p[i-1]);
	}
	if(mi>1)
	{
		ans+=mi-1;
		if(p[1]==mi||p[n]==mi);
		else ans+=mi+1;
	}
	if(ma>k)
	{
		ans+=ma-k;
		ans+=min(abs(p[1]-ma),abs(p[n]-ma));
	}
	cout<<ans<<endl;
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
1 2 3 4 5 6 7 8 

7 2 1 2 3 4 5 6 7 8 10
3 2 1
*/