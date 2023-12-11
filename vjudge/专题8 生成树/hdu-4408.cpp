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
class MatrixTree{
public:
	long long a[222][222];
	int n;
	void init(int _n){
		n=_n;
		memset(a,0,sizeof(a));
	}
	void add(int x,int y){
		a[x][x]++;
		a[y][y]++;
		a[x][y]--;
		a[y][x]--;
	}
	long long det()
	{
		ll res=1;
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				while(a[j][i]){
					ll t=a[i][i]/a[j][i];
					for(int k=i;k<=n;k++)
						a[i][k]=(a[i][k]-a[j][k]*t);
					for(int k=i;k<=n;k++)
						swap(a[i][k],a[j][k]);
					res=-res;
				}
			}
			if(a[i][i]==0)res=-res;
			res*=a[i][i];
		}
		if(res<0)res=-res;
		return res;
	}
}mt;
void solve()
{
	int n,m;ll p;
	cin>>n>>m>>p;
	mt.init(n);
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