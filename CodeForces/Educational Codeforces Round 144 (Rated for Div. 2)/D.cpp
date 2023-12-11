/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
const int INF=1e18+7;
const int maxn=1e6+100;
struct node{
	//ls 端点在最左边
	//rs 端点在最右边
	int sum,ls,rs,ts;
	node():sum(-INF),ls(-INF),rs(-INF),ts(-INF){}
	node(int x,int y,int z,int t):sum(x),ls(y),rs(z),ts(t){}
};
int p[maxn];
int n,k,x;
vector<node>MaxIn(int L,int R)
{
	if(L==R){
		int s1=max(0ll,p[L]-x);
		int s2=max(0ll,p[L]+x);
		if(k==0)
			return {node(p[L]-x,s1,s1,s1)};
		else
			return {node(p[L]-x,s1,s1,s1),node(p[L]+x,s2,s2,s2)};
	}
	int mid=(L+R)>>1;
	vector<node>ls = MaxIn(L,mid);
	vector<node>rs = MaxIn(mid+1,R);
	int len = min(k,R-L+1)+1;
	vector<node>ans(len);
	for(int i=0;i<ls.size();i++)
	{
		for(int j=0;j<rs.size()&&i+j<len;j++)
		{
			auto l=ls[i];
			auto r=rs[j];
			auto &t=ans[i+j];
			t.sum=max({t.sum,l.sum+r.sum});
			t.ls=max({t.ls, l.ls, l.sum+r.ls});
			t.rs=max({t.rs, r.rs, r.sum+l.rs});
			t.ts=max({t.ts, r.ts, l.ts, r.ls+l.rs});
		}
	}
	return ans;
}
void solve()
{
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cout<<MaxIn(1,n)[k].ts<<endl;
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