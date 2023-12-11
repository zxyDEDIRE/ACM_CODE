/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
	int x,y;
}a[maxn];
int p[maxn];
int s[maxn];
int t[maxn];
int n,k,m;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(i>k)
			a[++m]={p[i],i};
	}
	sort(a+1,a+1+m,[&](node a,node b){
		if(a.x!=b.x)return a.x<b.x;
		return a.y<b.y;
	});
	t[m+1]=INF;
	for(int i=m;i>=1;i--)
	{
		s[i]=a[i].x;
		t[i]=min(t[i+1],a[i].y);
	}
	int mi=INF;
	for(int i=1;i<=k;i++)
	{
		int fl=upper_bound(s+1,s+1+m,p[i])-s;
		// cout<<i<<" "<<p[i]<<" "<<fl<<endl;
		if(fl<=m)
			mi=min(mi,t[fl]-i);
	}
	if(mi==INF)cout<<-1<<endl;
	else cout<<mi<<endl;
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