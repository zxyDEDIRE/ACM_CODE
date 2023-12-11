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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
vector<int>w[maxn];
int f[maxn][25];
int dep[maxn];
int siz[maxn];
int n;
void RMQ(int x,int fa)
{	
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	siz[x]=1;
	for(int i=1;i<=20;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(auto y:v[x])
		if(y!=fa){
			RMQ(y,x);
			siz[x]+=siz[y];
		}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]>=dep[y])
			x=f[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]!=dep[f[y][i]])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		w[x].push_back(i);
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	RMQ(1,0);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(w[i].size()==0)
			cout<<1ll*n*(n-1)/2<<endl;
		else if(w[i].size()==1)
			cout<<1ll*(n-siz[w[i][0]])*siz[w[i][0]]<<endl;
		else
		{
			
		}
	}

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}