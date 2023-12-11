/*！*/
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
map<int,int>mp;
void dfs(int x,int y,int step)
{
	if(step>3)return ;
	// cout<<x<<" "<<step<<endl;
	if(x>y+100)return ;
	if(mp.count(x)&&step>mp[x])return ;
	mp[x]=step;
	for(int i=1;i<=10;i++)
	{
		if(x-i*i>=0)
		{
			dfs(x-i*i,y,step+1);
		}
		dfs(x+i*i,y,step+1);
	}
}
int ans[maxn];
int cnt=0;
void solve(int a,int b)
{
	mp.clear();
	cout<<a<<" "<<b<<endl;
	dfs(a,b,0);
	ans[++cnt]=mp[b];
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// solve(54,88);

	// int __;cin>>__;
	// srand(time(0));
	// while(__--){
	// 	int a,b;
	// 	a=rand()%100+1;
	// 	b=rand()%100+1;
	// 	while(a==b)a+=rand();
	// 	solve(a,b);
	// }
	// for(int i=1;i<=cnt;i++)
	// 	cout<<ans[i]<<" ";cout<<endl;

	// ll x=1e9;
	// cout<<sqrt(x)<<endl;

	ll x=33622;
	ll y=32622;
	cout<<x*x-y*y<<endl;

//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
66244000
*/