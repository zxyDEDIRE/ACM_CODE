/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
struct node{
	int id,dis;
}a[maxn],b[maxn];
int num_x[maxn];
int num_y[maxn];
map<int,int>mp_x,mp_y;
map<pii,int>mp;
int n,tot_x,tot_y;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y,w;
		cin>>x>>y>>w;
		if(!mp_x.count(x))mp_x[x]=++tot_x;
		if(!mp_y.count(y))mp_y[y]=++tot_y;
		x=mp_x[x];
		y=mp_y[y];
		num_x[x]+=w;
		num_y[y]+=w;
		mp[{x,y}]=w;
	}
	for(int i=1;i<=tot_x;i++)
		a[i].id=i,a[i].dis=num_x[i];
	for(int i=1;i<=tot_y;i++)
		b[i].id=i,b[i].dis=num_y[i];

	// for(int i=1;i<=tot_x;i++)
	// 	cout<<num_x[i]<<" ";cout<<endl;
	// for(int i=1;i<=tot_y;i++)
	// 	cout<<num_y[i]<<" ";cout<<endl;

	int ma=0;
	// for(auto [x,y]:mp)
	// 	ma=max(ma,num_x[x.first]+num_y[x.second]-y);
	// cout<<ma<<endl;
	sort(a+1,a+1+tot_x,[&](node a,node b){
		return a.dis>b.dis;
	});
	sort(b+1,b+1+tot_y,[&](node a,node b){
		return a.dis>b.dis;
	});
	auto f=[&](int i,int j)->int{
			int now=a[i].dis+b[j].dis;
			pii x={a[i].id,b[j].id};
			if(mp.count(x))now-=mp[x];
			return now;
	};
	for(int i=1;i<=min(2000*1ll,tot_x);i++)
	{
		for(int j=1;j<=min(2000*1ll,i);j++)
		{
			if(mp.count({a[i].id,b[j].id}))continue;
			if(a[i].dis+b[j].dis<ma)break;
			ma=max(ma,a[i].dis+b[j].dis);
		}
		if(!mp.count({a[i].id,b[1].id})&&a[i].dis+b[1].dis<ma)break;
	}
	cout<<ma<<endl;
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