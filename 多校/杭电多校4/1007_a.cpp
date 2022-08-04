/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
ll q[maxn];
ll p[maxn];
ll n,x,k;
void YES(){cout<<"YES"<<endl;}
void NO(){cout<<"NO"<<endl;}
void solve()
{
	cin>>n>>x>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		if(p[i]<=x)x+=p[i];
		else
		{
			int flag=0;
			int t=min(i+k-1,n);
			q[t+1]=x;
			for(int j=t;j>=i;j--)
			{
				if(p[j]<=q[j+1])q[j]=q[j+1]+p[j];
				else q[j]=x;
			}
			int s;
			for(s=i;s<=t;s++)
			{
				if(q[s]!=x)flag=1;
				if(q[s]==x)break;
			}
			if(!flag)return NO();
			x=q[i];
			i=s-1;
		}
	}
	return YES();
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}