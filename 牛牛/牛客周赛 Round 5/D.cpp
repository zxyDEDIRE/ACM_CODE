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
struct node{
	int op,x,len,l;
};
vector<node>v;
int n,m1,m2;
void solve()
{
	cin>>n>>m1>>m2;
	int l_1=1,l_2=0;
	for(int i=1;i<=m1;i++)
	{
		int x,y;cin>>x>>y;
		v.push_back({0,x,y,l_1});
		l_1+=y;
	}
	for(int i=1;i<=m2;i++)
	{
		int x,y;cin>>x>>y;
		v.push_back({0,x,y,l_2});
		l_2+=y;
	}
	sort(v.begin(),v.end(),[&](node a,node b){
		return a.l<b.l;
	});
	ll ans=0;
	int x_1,y_2;
	l_1=r_1=1;
	for(int i=0;i<(int)v.size();i++)
	{
		
	}
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