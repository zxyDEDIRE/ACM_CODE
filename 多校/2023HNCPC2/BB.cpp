/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
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
map<pii,int>mp;
int vis[maxn];
int in[maxn];
int n,m;
void NO(){cout<<"NO"<<endl;}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[{x,y}]=1;
		v[y].push_back(x);
		in[y]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)return NO();
		if(in[i]==1)q.push(i);
	}

	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:v[x])
		{
			if(vis[y]==x)continue;
			vis[x]=y;
			if(vis[y])break;
			if(mp.count({x,y}))
			{
				mp.erase({x,y});
				in[y]--;
				if(in[y]==1)q.push(y);
				else if(in[y]==0)return NO();
			}
			break;
		}
		if(!vis[x])return NO();
	}
	cout<<"YES"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}