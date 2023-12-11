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
int unit;  // 块的大小
struct node {
  int l, r, k,id;
  bool operator<(const node &x) const {
    return l / unit == x.l / unit
               ? (r == x.r ? 0 : ((l / unit) & 1) ^ (r < x.r))
               : l < x.l;
  }
}a[maxn];
int p[maxn];
int n,q;

void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	unit=sqrt(n);
	for(int i=1;i<=q;i++){
		auto &[l,r,k,id]=a[i];
		cin>>l>>r>>k;
		id=i;
	}
	sort(a+1,a+1+q);
	

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}