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
struct node{
	int l,r;
}p[maxn];
int n,m,ma;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>p[i].l>>p[i].r;
	sort(p+1,p+1+m,[&](node a,node b){
		if(a.l!=b.l)return a.l<b.l;
		return a.r<b.r;
	});
	int r=0;
	for(int i=1;i<=m;i++)
	{
		ma=max(ma,p[i].l-r-1);
		r=max(r,p[i].r);
	}
	ma=max(ma,n-r);
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