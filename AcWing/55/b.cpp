#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v,q;
int ans[maxn];
int p[maxn];
int n,m;
int main()
{	ios
	
	cin>>n>>m;
	for(int i=1;i<=n+m;i++)
		cin>>p[i];
	for(int i=1;i<=n+m;i++)
	{
		int x;cin>>x;
		if(x)q.push_back(p[i]);
		else v.push_back(p[i]);
	}
	
	// for(auto i:v)
	// 	cout<<i<<" ";cout<<endl;
	// for(auto i:q)
	// 	cout<<i<<" ";cout<<endl;

	for(auto i:v)
	{
		int fl=upper_bound(q.begin(),q.end(),i)-q.begin();
		if(fl==0)
		{
			ans[fl]++;
		}
		else if(fl==m)
		{
			ans[fl-1]++;
		}
		else
		{
			int a=q[fl];
			int b=q[fl-1];
			if(abs(a-i)<abs(b-i))ans[fl]++;
			else ans[fl-1]++;
		}
	}

	for(int i=0;i<m;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}