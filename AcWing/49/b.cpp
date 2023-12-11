/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int n,ans;
void solve()
{
	cin>>n;
	int ma=-maxn,mi=maxn;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]>0)ans+=p[i];
		if(p[i]&1)
		{
			if(p[i]>0)mi=min(mi,p[i]);
			if(p[i]<0)ma=max(ma,p[i]);
		}
	}

	if(ans&1)cout<<ans<<endl;
	else
	{
		ans=max(ans-mi,ans+ma);
		cout<<ans<<endl;
	}

}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}