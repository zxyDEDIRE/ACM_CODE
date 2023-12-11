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
vector<int>G[maxn];
int dis[maxn];
int num[maxn];
int out[maxn];
int ans[maxn];
int in[maxn];
int n,m;
void A()
{
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:v[x])
		{
			in[y]--;
			dis[y]+=dis[x];
			if(!in[y])
				q.push(y);
		}
	}
	cout<<"A"<<endl;
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
	cout<<endl;
}
void B()
{
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!out[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:G[x])
		{
			out[y]--;
			num[y]+=num[x];
			if(!out[y])
				q.push(y);
		}
	}
	cout<<"B"<<endl;
	for(int i=1;i<=n;i++)
		cout<<num[i]<<" ";
	cout<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ans[i]=-1;
		dis[i]=num[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		in[y]++;
		G[y].push_back(x);
		out[x]++;
	}
	A();
	B();
	for(int i=1;i<=n;i++)
	{
		// if(dis[i]+num[i]==n+1){
		// 	ans[dis[i]]=i;
		// }
		if(num[i]==n-dis[i]+1){
			ans[dis[i]]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i];
		if(i!=n)cout<<" ";
		else cout<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
5 5
1 2
2 5
3 4
3 5
4 5
*/