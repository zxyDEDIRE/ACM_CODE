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
const int INF=1e9+7;
const int maxn=1e6+100;
struct ST{
	int f[maxn][30];
	int h[maxn][30];
	int n;
	void init(int *p,int len)
	{
		n=len;
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=h[i][0]=p[i];
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++){
			for(int i=1;i<=n-(1<<j)+1;i++){
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				h[i][j]=min(h[i][j-1],h[i+(1<<(j-1))][j-1]);
			}
		} 
	}
	int query(int l,int r,int fl)
	{
		int k=log2(r-l+1);
		if(fl==0)
			return max(f[l][k],f[r-(1<<k)+1][k]);
		if(fl==1)
			return min(h[l][k],h[r-(1<<k)+1][k]);
		return 0;
	}
}st;
struct node{
	int x,y,id;
}p[maxn];
int id[maxn];
int a[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		p[i].id=i;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.x!=b.x)return a.x<b.x;
		else return a.y<b.y;
	});
	for(int i=1;i<=n;i++)
	{
		a[i]=p[i].x;
		b[i]=p[i].y;
		id[p[i].id]=i;
	}
	st.init(b,n);
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		x=id[x];y=id[y];
		if(a[x]>=a[y]){
			cout<<0<<endl;
			continue;
		}
		// if(x>y)swap(x,y);
		x=lower_bound(a+1,a+1+n,a[x])-a;
		y=upper_bound(a+1,a+1+n,a[y])-a-1;
		ll lx=a[y]-a[x];
		ll ly=st.query(x,y,0)-st.query(x,y,1);
		cout<<lx*ly<<endl;
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
/*
7
1 1
1 -1
1 0
3 5
7 2
-2 -3
4 4
1
7 5
*/