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
	int x,y;
}p[maxn];
struct ST{
	int f[maxn][30];
	int n;
	void init(int N)
	{
		n=N;
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=p[i].y-p[i].x+1;
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		} 
	}
	int query(int l,int r)
	{
		int k=log2(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
};
vector<int>T;
int len_a[maxn];
int len_b[maxn];
ST _a,_b;
int n,m;
void init()
{
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.y!=b.y)return a.y<b.y;
		return a.x<b.x;
	});
	for(int i=1;i<=n;i++)
		len_a[i]=p[i].y;
	_a.init(n);

	sort(p+1,p+1+n,[&](node a,node b){
		if(a.x!=b.x)return a.x<b.x;
		return a.y<b.y;
	});
	for(int i=1;i<=n;i++)
		len_b[i]=p[i].x;
	_b.init(n);
}
int pre(int k)
{
	int fl=upper_bound(len_a+1,len_a+1+n,k)-len_a;
	fl--;
	if(fl)return _a.query(1,fl);
	return -INF;
}
int suf(int k)
{
	int fl=lower_bound(len_b+1,len_b+1+n,k)-len_b;
	if(fl<=n)return _b.query(fl,n);
	return -INF;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		T.push_back(p[i].x);
		T.push_back(p[i].y);
	}
	sort(T.begin(),T.end());
	T.erase(unique(T.begin(),T.end()),T.end());
	init();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,p[i].y-p[i].x+1+pre(p[i].x));
		ans=max(ans,p[i].y-p[i].x+1+suf(p[i].y));
	}
	cout<<ans<<endl;



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
/*
4 8
2 6
4 8
2 7
1 5
*/