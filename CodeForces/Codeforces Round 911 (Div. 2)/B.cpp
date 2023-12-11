#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
#define pp(x) array<int,x>
int a,b,c;
// map<pp(3),bool>ma,mb,mc;
set<pp(3)>ma,mb,mc;
void dfs(int a,int b,int c,set<pp(3)>&mp)
{
	if(a>100||b>100||c>100)return ;
	if(mp.count({a,b,c}))return ;
	// mp[{a,b,c}]=1;
	mp.insert({a,b,c});
	if(a>0)dfs(a-1,b+1,c+1,mp);
	if(b>0)dfs(a+1,b-1,c+1,mp);
	if(c>0)dfs(a+1,b+1,c-1,mp);
}
void init()
{
	for(int i=1;i<=100;i++)
		dfs(i,0,0,ma);
	for(int i=1;i<=100;i++)
		dfs(0,i,0,mb);
	for(int i=1;i<=100;i++)
		dfs(0,0,i,mc);
	// cout<<"initok"<<endl;
}
void solve()
{
	cin>>a>>b>>c;
	if(ma.count({a,b,c}))cout<<1<<" ";
	else cout<<0<<" ";

	if(mb.count({a,b,c}))cout<<1<<" ";
	else cout<<0<<" ";

	if(mc.count({a,b,c}))cout<<1<<"\n";
	else cout<<0<<"\n";

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1 0 0
0 1 1

1 1 0

给你a,b,c三个数字
一次操作 一个数字+1 ，另外两个数字-1
不能小于0
问最后是否
a!=0,b=c=0
b!=0,a=c=0;
c!=0,a=b=0;

82 47 59


1 3 1
0 3 0

0 0 2
*/