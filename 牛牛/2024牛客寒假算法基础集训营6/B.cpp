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
int a[maxn],b[maxn],p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i]=a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	sort(a+1,a+1+n);
	int mi=INF,_x=0,_j=0;
	for(int i=1;i<=n;i++)
	{
		int x=b[i];
		int fl=lower_bound(a+1,a+1+n,x)-a;
		if(fl<=n && fl>=1)
		{
			int now=abs(x-a[fl]);
			if(now<mi)
			{
				mi=now;_x=a[fl];_j=i;
			}
		}
		fl--;
		if(fl>=1&&fl<=n)
		{
			int now=abs(x-a[fl]);
			if(now<mi)
			{
				mi=now;_x=a[fl];_j=i;
			}
		}
	}
	int fl=0;
	for(int i=1;i<=n;i++)
		if(p[i]==_x){
			fl=i;
			break;
		}
	swap(p[fl],p[_j]);
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";cout<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}