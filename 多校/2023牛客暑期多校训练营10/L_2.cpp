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
const int N=1e4;
struct pp
{
	int r,g,b;
	bool operator == (const pp w){
		return (r==w.r)&&(g==w.g)&&(b==w.b);
	}
	bool operator >(const pp w){
		return r>w.r&&g>w.g&&b>w.b;
	}
}p[N];
vector<int>v[N],G[N];
int ans[maxn];
int out[maxn];
int in[maxn];
int n;
int A()
{
	queue<int>q;
	q.push(1);
	q.push(2);
	int ma=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		ma=max(ma,ans[x]);
		for(auto y:v[x])
		{
			if(ans[y]<ans[x]+1)
			{
				ans[y]=ans[x]+1;
				q.push(y);
			}
		}
	}
	return ma;
}
int B()
{
	queue<int>q;
	q.push(1);
	q.push(2);
	int mi=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		mi=min(mi,ans[x]);
		for(auto y:G[x])
		{
			if(ans[y]>0)return INF;
			if(ans[y]>ans[x]-1)
			{
				ans[y]=ans[x]-1;
				q.push(y);
			}
		}
	}
	return mi;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		p[i]={x,y,z};
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(p[j]>p[i]){
				v[i].push_back(j);
				G[j].push_back(i);
				out[i]++;
				in[j]++;
			}
		}
	}
	int x=A();
	int y=B();
	if(y==INF || p[1]>p[2] ||p[2]>p[1])cout<<"-1"<<endl;
	else if(x-y>255)cout<<"-1"<<endl;
	else
	{
		for(int i=1;i<=n;i++)
			cout<<ans[i]-y<<endl;
	}
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
5
6 10 6
6 10 7
5 5 5
6 6 10
7 7 11
*/