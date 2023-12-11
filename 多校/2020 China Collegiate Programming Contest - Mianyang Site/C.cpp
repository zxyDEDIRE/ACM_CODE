#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<vector<string>>v;
vector<int>p;
int t[maxn][26],indx;
map<int,int>mp;
bool mst[maxn];
bool mno[maxn];
bool _end[maxn];
int FLAG;
int tot;
int n;
void clear()
{
	FLAG=1;
	for(int i=0;i<=tot;i++)
	{
		for(int j=0;j<26;j++)
			t[i][j]=0;
		mst[i]=mno[i]=_end[i]=0;
	}
	tot=0;
	v.clear();
	p.clear();
	indx=0;
	mp.clear();
	// _end[0]=1;
}
void insert(string&str)
{
	int rt=0;
	for(auto i:str)
	{
		int tmp=i-'a';
		if(!t[rt][tmp])
			t[rt][tmp]=++indx;
		rt=t[rt][tmp];
	}
	_end[rt]=1;
}
int add_lca(string&str)
{
	int rt=0;
	for(auto i:str)
		rt=t[rt][i-'a'];
	if(mst[rt])FLAG=0;
	mst[rt]=1;
	return rt;
}
void find_end(int x)
{
	for(int i=0;i<26;i++)
	{
		if(!t[x][i])continue;
		int y=t[x][i];
		// if(mno[x])mno[y]=1;
		find_end(y);
		if(_end[x]&&!mno[y])
			mst[y]=1;
		// if(mst[y])mst[x]=1;
	}
}
void solve()
{
	cin>>n;
	clear();
	for(int i=1;i<=n;i++)
	{
		string str;int x;
		cin>>str>>x;
		insert(str);
		if(!mp.count(x))mp[x]=tot++,v.push_back(vector<string>()),p.push_back(x);
		v[mp[x]].push_back(str);
	}
	for(int x=0;x<tot;x++)
	{
		if(v[x].size()==1)continue;
		string now;
		for(int i=0;;i++)
		{
			int flag=1;
			for(int j=0;j<v[x].size();j++)
			{
				if(v[x].size()==i){flag=0;break;}
				if(v[x][j][i]!=v[x][0][i]){flag=0;break;}
			}
			if(!flag)break;
			now=now+v[x][0][i];
		}
		int lca=add_lca(now);
		int len=now.size();
		cout<<"now "<<now<<endl;
		cout<<"LCA "<<lca<<endl;
		for(int i=0;i<v[x].size();i++)
		{
			if(v[x][i].size()<=len)continue;
			char mp=v[x][i][len];
			int tmp=t[lca][mp-'a'];
			cout<<"mno "<<tmp<<" mp:"<<mp<<endl;
			mno[tmp]=1;
		}
	}
	find_end(0);
	int ans=0;
	for(int i=0;i<=tot;i++)
	{
		ans+=mst[i];
		if(mst[i]&&mno[i])FLAG=0;
		cout<<i<<" "<<mst[i]<<" "<<mno[i]<<endl;
	}
	if(!FLAG){cout<<"-1\n";}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}
/*
多个串的LCA必选
多个串LCA的子节点必选不存在
串末尾节点有子节点 必存在
*/