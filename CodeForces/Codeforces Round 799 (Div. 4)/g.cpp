#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int t[maxn];
int n,k;
void solve()
{
	cin>>n>>k;k++;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		t[i]=0;
	}
	int ans=0;
	t[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(p[i]*2>p[i-1])
		{
			t[i]=t[i-1]+1;
			if(t[i]>=k)ans++;
		}
		else t[i]=1;
	}
	cout<<ans<<endl;
}
int main()
{	ios
	int __;cin>>__;
	while(__--)solve();
}