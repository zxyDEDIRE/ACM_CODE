#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6;
vector<int>v[maxn];
int in[maxn];
int p[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	while(cin>>n&&n)
	{
		cin>>m;
		for(int i=1;i<=n;i++)
			in[i]=0,p[i]=i;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			in[x]++;
			in[y]++;
			int fa=find(x);
			int fb=find(y);
			if(fa!=fb)p[fa]=fb;
		}
		int flag=1;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(in[i]&1)
				flag=0;
			if(p[i]==i)
				cnt++;
		}
			
		if(flag&&cnt==1)cout<<1<<endl;
		else  cout<<0<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
}