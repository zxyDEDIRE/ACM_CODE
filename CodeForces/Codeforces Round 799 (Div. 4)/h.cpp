#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
map<int,int>mp;
vector<int>p;
int n,x,cnt;
void init()
{
	mp.clear();
	p.clear();
	cnt=0;
}
void solve()
{
	cin>>n;
	init();
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(mp.count(x)==0)
		{
			mp[x]=cnt++;
			v[mp[x]].clear();
			v[mp[x]].push_back(i);
			p.push_back(x);
		}
		else v[mp[x]].push_back(i);
	}
	int ans=p[0],l=1,r=1,ma=1;

	// for(int i=0;i<cnt;i++)
	// {
	// 	cout<<"i:"<<i<<" "<<p[i]<<endl;
	// 	for(auto j:v[i])
	// 		cout<<j<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;
	for(int i=0;i<cnt;i++)
	{
		 int mi=0,ll=v[i][0];
		for(int j=0;j<v[i].size();j++)
		{
			int x=j-(v[i][j]-j);
			if(x<mi)
			{
				mi=x;
				ll=v[i][j];
			}
			int res=x-mi+1;
			if(res>ma)
			{
				ans=p[i];
				ma=res;
				l=ll;
				r=v[i][j];
			}
		}
	}

	cout<<ans<<" "<<l<<" "<<r<<endl;

}
int main()
{	ios
	int __;cin>>__;
	while(__--)solve();
}
/*
1 2 4 5
*/