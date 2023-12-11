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
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
map<string,int>mp;
int vis[maxn];
int in[maxn];
int tot,n,m;
void init()
{
	for(int i=1;i<=tot;i++)
		vis[i]=0,v[i].clear(),in[i]=0;
	tot=0;
	mp.clear();
}
pii dfs(int x,int fa)
{
	if(vis[x]==1)
		return {1,0};
	if(vis[x]==-1)
		return {0,1};
	pii ans={0,0};
	for(auto y:v[x])
	{
		pii t=dfs(y,x);
		if(t.second)ans.second=1;
		ans.first+=t.first;
	}
	if(!ans.second&&ans.first)ans.first=1;
	return ans;
}
void solve()
{
	init();
	cin>>n>>m;
	for(int j=1;j<=n;j++)
	{
		string str,a="";
		int last=0;
		cin>>str;
		str+='#';
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='/')
			{
				if(!mp.count(a))mp[a]=++tot;
				int x=mp[a];
				if(last)
				{
					v[last].push_back(x);
					in[x]++;
				}
				last=x;
				a="";
			}
			else if(str[i]=='#')
			{
				if(!mp.count(a))mp[a]=++tot;
				int x=mp[a];
				if(last)
				{
					v[last].push_back(x);
					in[x]++;
				}
				vis[x]=1;
			}
			else a+=str[i];
		}
	}
	for(int j=1;j<=m;j++)
	{
		string str,a="";
		int last=0;
		cin>>str;
		str=str+'#';
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='/')
			{
				if(!mp.count(a))
					mp[a]=++tot;
				int x=mp[a];
				if(last)
				{
					v[last].push_back(x);
					in[x]++;
				}
				last=x;
				a="";
			}
			else if(str[i]=='#')
			{
				if(!mp.count(a))
					mp[a]=++tot;
				int x=mp[a];
				if(last)
				{
					v[last].push_back(x);
					in[x]++;
				}
				vis[x]=-1;
			}
			else a+=str[i];
		}
	}
	int ans=0;
	for(int i=1;i<=tot;i++)
	{
		if(!in[i])
		{
			pii t=dfs(i,0);
			ans+=t.first;
		}
	}
	cout<<ans<<endl;
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
3 2
data/train
data/test
model
abb
data/bbb/aaa
*/