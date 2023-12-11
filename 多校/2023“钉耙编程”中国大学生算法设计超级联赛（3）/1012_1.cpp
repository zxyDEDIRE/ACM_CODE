#include<bits/stdc++.h>
using namespace std;

const int N=4e6+10;
int n,q;
int p;
map<pair<pair<int,long long>,long long>,int>mp[2];
vector<long long>tr[N];
void insert(vector<pair<int,long long>>&v,long long gc)
{
	int id=0;
	for(int i=(int)v.size()-1;i>=0;i--)
	{
		int f=v[i].first;
		long long val=v[i].second;
		if(mp[f].count({{id,gc},val})==false)
		{
			mp[f][{{id,gc},val}]=++p;
		}
		id=mp[f][{{id,gc},val}];
		tr[id].push_back(val);
	}
}
int qr(vector<pair<int,long long>>&v,long long gc)
{
	int id=0;
	for(int i=(int)v.size()-1;i>=0;i--)
	{
		int f=v[i].first;
		long long val=v[i].second;
		if(mp[f].count({{id,gc},val})==false)
		{
			return 0;
		}
		id=mp[f][{{id,gc},val}];
	}
	int t=lower_bound(tr[id].begin(),tr[id].end(),v[0].second)-tr[id].begin();
	return tr[id].size()-t;
}
void solve()
{
	cin>>n>>q;
	mp[0].clear();mp[1].clear();
	for(int i=0;i<=p;i++) tr[i].clear();
	p=0;
	for(int i=1;i<=n;i++)
	{
		long long a,b;
		cin>>a>>b;
		vector<pair<int,long long>>v;
		while(a)
		{
			int f=0;
			long long cnt=0;
			if(a>=b)
			{
				f=0;
				cnt=a/b;
				a=a-cnt*b;
			}
			else{
				f=1;
				cnt=b/a;
				b=b-cnt*a;
				if(b==0) {
				b+=a;cnt--;
				}
			}
			v.push_back({f,cnt});
		}		
		insert(v,b);
	}
	for(int i=0;i<=p;i++) sort(tr[i].begin(),tr[i].end());
	while(q--)
	{
		long long a,b;
		cin>>a>>b;
		vector<pair<int,long long>>v;
		while(a)
		{
			int f=0;
			long long cnt=0;
			if(a>=b)
			{
				f=0;
				cnt=a/b;
				a=a-cnt*b;
			}
			else{
				f=1;
				cnt=b/a;
				b=b-cnt*a;
				if(b==0) {
					b+=a;
					cnt--;
				}
			}
			v.push_back({f,cnt});
		}
		cout<<qr(v,b)<<'\n';
	}
}
/*
*/
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	 } 
	return 0;
} 