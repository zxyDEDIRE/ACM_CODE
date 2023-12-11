#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
vector<int>v[111];
array<int,2>p[111];
long long t;
int n;
void solve()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>p[i][0]>>k;
		p[i][1]=i;
		while(k--){
			int x;cin>>x;
			v[i].push_back(x);
		}
	}
	sort(p+1,p+1+n,[&](auto a,auto b){
	   return a[0]<b[0]; 
	});
	int ma=0;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=1;i<=n;i++)
	{
		long long now=p[i][0];
		while(q.size())q.pop();
		for(int j=1;j<=i;j++)
			for(auto x:v[p[j][1]])
				q.push(x);
		int cnt=0;
		while(q.size())
		{
			int x=q.top();q.pop();
			if(x+now<=t)
			{
				cnt++;
				now+=x;
			}
			else break;
		}
		ma=max(ma,cnt);
	}
	cout<<ma<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}