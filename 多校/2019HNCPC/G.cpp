D/*
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
const int N=2e3+100;
priority_queue<int,vector<int>,greater<int>>q;
bitset<N>s[N],t[N],vis;
vector<int>v;
int a[N][N];
int n,m;
void solve()
{
	for(int i=1;i<=m;i++)
		s[i].reset(),t[i].reset();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	v.clear();
	vis.reset();
	for(int i=1;i<=m;i++)
	{
		int cnt=0;
		s[i][1]=t[i][1]=1;
		for(int j=2;j<=n;j++)
			if(a[j-1][i]<=a[j][i])
				s[i][j]=1;
		cnt=s[i].count();
		if(cnt==n)q.push(i),vis[i]=1;
		else v.push_back(i);
		for(int j=2;j<=n;j++)
			if(a[j-1][i]<a[j][i])
				t[i][j]=1;
	}
	vector<int>ans;
	while(!q.empty())
	{
		int x=q.top();q.pop();
		ans.push_back(x);
		for(auto y:v)
		{
			if(vis[y])continue;
			s[y]|=t[x];
			if(s[y].count()==n)
				q.push(y),vis[y]=1;
		}
	}
	if(ans.size()!=m)cout<<-1<<endl;
	else
	{
		for(auto i:ans)
			cout<<i<<" ";
		cout<<endl;
	}
	
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	while(cin>>n>>m)
	// cin>>n>>m;
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}