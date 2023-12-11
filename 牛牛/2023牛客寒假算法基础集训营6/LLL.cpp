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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int M=1e9+7;
int ff[maxn];
vector<pii>v;
int p[maxn];
int n,m;
int fp(int b,int p)
{
	int r=1;b%=mod;
	while(p){
		if(p&1)r=(r*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return r;
}
//求最大公因数
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
 
//解线性同余方程，扩展欧几里德定理
int x,y;
void Extended_gcd(int a,int b)
{
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        Extended_gcd(b,a%b);
        long t=x;
        x=y;
        y=t-(a/b)*y;
    }
}
 
//计算不大的C(n,m)
int C(int a,int b)
{
    if(b>a)
        return 0;
    b=(ff[a-b]*ff[b])%mod;
    a=ff[a];
    int c=gcd(a,b);
    a/=c;
    b/=c;
    Extended_gcd(b,M);
    x=(x+M)%M;
    x=(x*a)%M;
    return x;
}
 
//Lucas定理
int Combination(int n, int m)
{
	if(n<m)swap(n,m);
    int ans=1;
    int a,b;
    while(m||n)
    {
        a=n%mod;
        b=m%mod;
        n/=M;
        m/=M;
        ans=(ans*C(a,b))%mod;
    }
    return ans%mod;
}
void solve()
{
	cin>>n>>m;
	int sum=pow(2,n-1);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v.push_back({x,y});
	}
	sort(v.begin(),v.end(),[&](pii a,pii b){
		if(a.first!=b.first)return a.first<b.first;
		return a.second<b.second;
	});
	for(int i=0;i<v.size();i++)
	{
		// cout<<i<<endl;
		auto [x,y]=v[i];
		int l=x+y-1;
		p[i]+=Combination(l-1,l-x);
		p[i]%=mod;
		for(int j=i+1;j<v.size();j++)
		{
			// cout<<"j"<<j<<endl;
			auto [xx,yy]=v[j];
			if(xx>=x&&yy>=y){
				// cout<<"Yes"<<endl;
				int _len=xx-x+yy-y+1;
				p[j]-=p[i]*Combination(_len-1,_len-(xx-x)-1);
			}
		}
		// cout<<"OK"<<endl;
		int len=min(n-y+1-x,n-x+1-y);
		// cout<<x<<" "<<y<<endl;
		len=max(len,0ll);
		int op=p[i]*fp(2,len)%mod;
		sum=(sum-op)%mod;
		sum%=mod;
	}
	cout<<sum%mod<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	ff[0]=1;
    for(int i=1; i<=2e5+10; i++) //预计算n!
        ff[i]=(ff[i-1]%mod*i)%mod;
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
5 3
3 1
3 5
1 3
*/