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
	int val,l,r;
}t[maxn];
map<int,int>mp;
int p[maxn];
int n,tot,x;
void build(int rt,int x)
{
	if(!t[rt].val){
		t[rt].val=x;
		return ;
	}
	if(x>t[rt].val){
		if(!t[rt].r)t[rt].r=++tot;
		build(t[rt].r,x);
	}
	if(x<t[rt].val){
		if(!t[rt].l)t[rt].l=++tot;
		build(t[rt].l,x);
	}
}
void solve()
{
	while(cin>>x)
		p[++n]=x,build(1,x);
	sort(p+1,p+1+n,[&](int a,int b){
		return a>b;
	});
	for(int i=1;i<=n;i++)
		mp[p[i]]=i;
	
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