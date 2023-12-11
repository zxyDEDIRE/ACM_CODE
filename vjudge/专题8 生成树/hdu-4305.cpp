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
const int mod=10007.;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int exgcd(int a,int b,int& x,int& y)
{
	if(b==0)return x=1,y=0,a;
	int d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
int inv(int a,int p){
	int x,y;
	exgcd(a,p,x,y);
	x=(x%p+p)%p;
	return x;
}
int x,y;
class MatrixTree{
public:
	long long a[333][333];
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
					ll t=(a[i][i]*inv(a[j][i],mod))%mod;

					for(int k=i;k<=n;k++){
						a[i][k]=(a[i][k]-a[j][k]*t%mod)%mod;
						a[i][k]=(a[i][k]%mod+mod)%mod;
					}
					for(int k=i;k<=n;k++)
						swap(a[i][k],a[j][k]);
					res=-res;
					res=(res%mod+mod)%mod;
				}
			}
			if(a[i][i]==0)res=-res;
			res=(res%mod+mod)%mod;
			res*=a[i][i];
			res%=mod;
		}
		if(res<0)res=-res;
		res=(res%mod+mod)%mod;
		if(res==0)res--;
		return res;
	}
}mt;
pii p[maxn];
int n,r;
bool ok(int x,int y)
{
	int dis=(p[x].first-p[y].first)*(p[x].first-p[y].first)+(p[x].second-p[y].second)*(p[x].second-p[y].second);
	return dis<=r*r;
}
bool A(pii &x,pii &y,pii &i)
{
	int disa=(x.first-i.first)*(x.first-i.first)+(x.second-i.second)*(x.second-i.second);
	int disb=(i.first-y.first)*(i.first-y.first)+(i.second-y.second)*(i.second-y.second);
	return disa<disb;
}
void solve()
{
	cin>>n>>r;
	mt.init(n);
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	for(int i=1;i<n;i++)
	{
		sort(p+1+1+i,p+1+n,[&](pii &a,pii &b){
			return A(a,b,p[i]);
		});
		for(int j=i+1;j<=n;j++)
		{
			if(!ok(i,j))continue;
			int flag=1;
			for(int k=i+1;k<j;k++)
			{
				double A=hypot(p[i].first-p[j].first,p[i].second-p[j].second);
				double a=hypot(p[i].first-p[k].first,p[i].second-p[k].second);
				double b=hypot(p[j].first-p[k].first,p[j].second-p[k].second);
				if(A==a+b)flag=0;
			}
			if(flag){
				mt.add(i,j);
			}
		}
	}
	cout<<mt.det()<<endl;
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
https://exastris.wjx.cn/vm/r7ez40D.aspx 作者：来自星尘 https://www.bilibili.com/read/cv26618705/?spm_id_from=333.999.0.0 出处：bilibili
*/