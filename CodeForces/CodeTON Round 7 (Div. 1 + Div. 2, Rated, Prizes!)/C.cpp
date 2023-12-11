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
	int x,id;
}a[maxn],b[maxn],c[maxn];
int n,k;
bool cmp(node a,node b)
{
	return a.x<b.x;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i].x,a[i].id=i;
	for(int i=1;i<=n;i++)
		cin>>b[i].x,b[i].id=i;
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	int tot=0;
	for(int i=n-k+1;i<=n;i++)
		c[++tot]=a[i];
	for(int i=1;i<n-k+1;i++)
		c[++tot]=a[i];

	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i].x>b[i].x)
			cnt++;
		b[i].id=c[i].id;
	}
	if(cnt!=k){
		cout<<"NO\n";
		return ;
	}
	sort(b+1,b+1+n,[&](node a,node b){
		return a.id<b.id;
	});
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
		cout<<b[i].x<<" ";
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1 2 3 4 5
2 3 5 1 2


3 2
2 4 3
4 1 2
*/