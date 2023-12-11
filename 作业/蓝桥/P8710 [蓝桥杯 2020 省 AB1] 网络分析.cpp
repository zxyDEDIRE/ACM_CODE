/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
int num[maxn];
int ans[maxn];
int p[maxn];
int n,m,tot;
int find(int r){
	return p[r]=(p[r]==r)?p[r]:find(p[r]);
}
void dfs(int x)
{
	ans[x]+=num[x];
	for(auto y:v[x])
	{
		ans[y]+=ans[x];
		dfs(y);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i;
	tot=n;
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			int fa=find(x);
			int fb=find(y);
			if(fa!=fb)
			{
				++tot;
				p[tot]=tot;
				p[fa]=tot;
				p[fb]=tot;
				v[tot].push_back(fa);
				v[tot].push_back(fb);
				// cout<<"Edge:"<<tot<<" "<<fa<<endl;
				// cout<<"Edge:"<<tot<<" "<<fb<<endl;
			}
		}
		else
		{
			cin>>x>>y;
			int fa=find(x);
			// cout<<"Num:"<<fa<<" "<<y<<endl;
			num[fa]+=y;
		}
	}
	for(int i=1;i<=tot;i++)
		if(p[i]==i)dfs(i);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}