
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")

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
int tmp;
struct Query{
	int l,r,id;
	bool operator<(const Query &x) const {
    return l / tmp == x.l / tmp
               ? (r == x.r ? 0 : ((l / tmp) & 1) ^ (r < x.r))
               : l < x.l;
  }
}p[maxn];
bitset<maxn>vis;
vector<int>v;
int ans[maxn];
int a[maxn];
int n,m,cnt;
void add(int x)
{
	for(auto y:v)
		if(y-x>=1&&y-x!=x&&vis[y-x])cnt++;
	vis[x]=1;
}
void del(int x)
{
	for(auto y:v)
		if(y-x>=1&&y-x!=x&&vis[y-x])cnt--;
	vis[x]=0;
}
void solve()
{
	cin>>n;
	v.clear();
	for(int i=2;i*i<n*2;i++)
		v.push_back(i*i);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=0;
	}
	tmp=sqrt(n);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>p[i].l>>p[i].r;
		p[i].id=i;
	}
	sort(p+1,p+1+m);

	cnt=0;
	for(int i=p[1].l;i<=p[1].r;i++){
		add(a[i]);
	}
	ans[p[1].id]=cnt;
	int l=p[1].l;
	int r=p[1].r;
	for(int i=2;i<=m;i++)
	{
		while(l<p[i].l)del(a[l]),l++;
		while(l>p[i].l)l--,add(a[l]);

		while(r<p[i].r)r++,add(a[r]);
		while(r>p[i].r)del(a[r]),r--;
		ans[p[i].id]=cnt;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __=1;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}