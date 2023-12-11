#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
ll v[2000];
ll n,k,ans;
void solve()
{
	cin>>n>>k;
	ans=0;
	for(int i=0;i<=k;i++)v[i]=0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		ans+=p[i]/k;
		if(p[i]%k)v[p[i]%k]++;
	}
	
	int l=1,r=k-1;
	while(l<r)
	{
		int t=l+r;
		if(t>=k)
		{
			ll s=min(v[l],v[r]);
			ans+=s;
			v[l]-=s;
			v[r]-=s;
			if(v[l]==0)l++;
			if(v[r]==0)r--;
		}
		else l++;
	}
	for(int i=1;i<k;i++){
		if(v[i])
		{
			if(i+i>=k)ans+=(v[i])/2;
			v[i]=0;
		}
	}
	
	cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}
/*
5
0 1 2 3 4
2 3 2 2 2
*/