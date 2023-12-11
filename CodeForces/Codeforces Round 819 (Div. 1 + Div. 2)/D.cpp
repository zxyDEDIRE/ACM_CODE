/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
bitset<maxn>vis;
vector<int>v;
int pa[maxn];
int pb[maxn];
pii p[maxn];
int fla,flb,fl;
int n,m;
int finda(int r){
	return pa[r]=pa[r]==r?pa[r]:finda(pa[r]);
}
int findb(int r){
	return pb[r]=pb[r]==r?pb[r]:findb(pb[r]);
}
int swap(int x){
	vis[x]=!vis[x];
}
int doit(int a)
{
	for(int i=1;i<=n;i++)
		pa[i]=pb[i]=i;
	for(int i=1;i<=m;i++)
	{
		auto [x,y]=p[i];
		int op=0;
		if(!vis[i]&&x!=a&&y!=a)op=1;
		if(vis[i]&&(x==a||y==a))op=1;
		if(!vis[i]&&(x==fla&&y==flb)||(x==flb&&y==fla))op=1;



		if(op)
		{
			int fa=findb(x);
			int fb=findb(y);
			pb[fa]=fb;
		}
		else
		{
			int fa=finda(x);
			int fb=finda(y);
			pa[fa]=fb;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(pa[i]==i)cnt++;
		if(pb[i]==i)cnt++;
	}
	return cnt;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		pa[i]=pb[i]=i;
	vis.reset();
	fla=flb=fl=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		p[i]={x,y};
		int fa=finda(x);
		int fb=findb(y);
		if(fa!=fb)
		{
			pa[fa]=fb;
			vis[i]=1;
		}
		else v.push_back(i);
	}
	for(auto i:v)
	{
		auto [x,y]=p[i];
		int fa=findb(x);
		int fb=findb(y);
		if(fa!=fb)
		{
			pb[fa]=fb;
		}
		else
		{
			fla=x;
			flb=y;
			fl=i;
		}
	}
	if(fl)
	{
		int x=doit(fla);
		int y=doit(flb);
		if(x<=y)
		{
			int a=fla,op;
			for(int i=1;i<=m;i++)
			{
				if(!vis[i]&&x!=a&&y!=a)op=1;
				if(vis[i]&&(x==a||y==a))op=1;
				if(!vis[i]&&(x==fla&&y==flb)||(x==flb&&y==fla))op=1;
				if(op)vis[i]=0;
				else vis[i]=1;
			}
		}
		else
		{
			int a=flb,op;
			for(int i=1;i<=m;i++)
			{
				if(!vis[i]&&x!=a&&y!=a)op=1;
				if(vis[i]&&(x==a||y==a))op=1;
				if(!vis[i]&&(x==fla&&y==flb)||(x==flb&&y==fla))op=1;
				if(op)vis[i]=0;
				else vis[i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<vis[i];
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
5 7
1 2
2 3
3 4
4 5
5 1
1 3
3 5
*/