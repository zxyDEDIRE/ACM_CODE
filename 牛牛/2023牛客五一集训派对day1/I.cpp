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
pii p[maxn];
int w[maxn];
int in[maxn];
int n,m,flag,cnt;
void dfs(int x)
{
	if(flag)return ;
	if(cnt==n){
		flag=1;
		return ;
	}
	if(x>m)return ;
	dfs(x+1);
	auto [_x,_y]=p[x];
	if(in[_x]>w[_x]&&in[_y]>w[_y])
	{
		in[_x]--;
		in[_y]--;
		if(in[_x]==w[_x])cnt++;
		if(in[_y]==w[_y])cnt++;
		dfs(x+1);
		if(in[_x]==w[_x])cnt--;
		if(in[_y]==w[_y])cnt--;
		in[_x]++;
		in[_y]++;
	}
}
void solve()
{
	for(int i=1;i<=n;i++)
		cin>>w[i],in[i]=0;
	for(int i=1;i<=m;i++)
	{
		auto &[x,y]=p[i];
		cin>>x>>y;
		in[x]++;
		in[y]++;
	}
	for(int i=1;i<=n;i++)
		if(in[i]<w[i]){
			cout<<"No"<<endl;return ;
		}
	for(int i=1;i<=m;i++)
	{
		auto &[x,y]=p[i];
		if(in[x]<in[y])swap(x,y);
	}
	sort(p+1,p+1+m,[&](pii a,pii b){
		return in[a.first]>in[b.first];
	});
	cnt=0;
	for(int i=1;i<=n;i++)
		if(in[i]==w[i])cnt++;
	flag=0;
	dfs(1);
	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n>>m)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}