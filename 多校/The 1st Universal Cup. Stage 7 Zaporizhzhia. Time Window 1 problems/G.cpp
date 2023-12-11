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
const int mod=1e9+9;
const int inf=0x3f3f3f3f;
const int INF=1e9+9;
const int maxn=1e6+100;
const int M = 5e5+10;
int p[maxn];
int n,sum;
void NO(){cout<<0<<endl;}
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int ff[M+5];  //打表，记录n!，避免重复计算
 
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
    b=(ff[a-b]%mod*ff[b])%mod;
    a=ff[a];
    int c=gcd(a,b);
    a/=c;
    b/=c;
    Extended_gcd(b,M);
    x=(x+mod)%mod;
    x=(x*a)%mod;
    return x;
}
 
//Lucas定理
int Combination(int n, int m)
{
    int ans=1;
    int a,b;
    while(m||n)
    {
        a=n%mod;
        b=m%mod;
        n/=mod;
        m/=mod;
        ans=(ans*C(a,b))%mod;
    }
    return ans;
}
int A(int n,int m)
{
    return (Combination(n,m)*ff[m])%mod;
}
 
void solve()
{
	cin>>n;
	map<int,bool>mp;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		sum+=p[i];
		mp[p[i]]=1;
	}
	if(n&1)
	{
		if(sum%n)return NO();
		map<pii,int>num;
		int tmp=sum/n*2;
		for(int i=1;i<=n;i++)
		{
			int x=p[i];
			int y=tmp-p[i];
			if(!mp.count(y))return NO();
			if(x>y)swap(x,y);
			num[{x,y}]++;
		}
		int ans=1;
		int cnt=0;
		for(auto [x,y]:num)
			if(x.first!=x.second)
				cnt+=y/2;
		ans=ksm(2,cnt);
		ans=(ans*A(n/2,n/2))%mod;
		for(auto [x,y]:num)
			ans=(ans*ksm(A(y/2,y/2),mod-2))%mod;
		cout<<ans<<endl;
	}
	else
	{
		if(sum%(n/2))return NO();
		map<pii,int>num;
		int tmp=sum/(n/2);
		for(int i=1;i<=n;i++)
		{
			int x=p[i];
			int y=tmp-x;
			if(!mp.count(y))return NO();
			if(x>y)swap(x,y);
			num[{x,y}]++;
		}
		int ans=1;
		int cnt=0;
		for(auto [x,y]:num)
			if(x.first!=x.second)
				cnt+=y/2;
		ans=ksm(2,cnt);
		ans=(ans*A(n/2,n/2))%mod;
		for(auto [x,y]:num)
			ans=(ans*ksm(A(y/2,y/2),mod-2))%mod;
		cout<<ans<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\p.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	ff[0]=1;
    for(int i=1; i<=M; i++) //预计算n!
        ff[i]=(ff[i-1]*i)%mod;
	int __;cin>>__;
	while(__--)
		solve();
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}
/*
1
5
1 2 2 2 3 

1 2 2 2 3
3 2 2 2 1
2 1 2 3 2
2 3 2 1 2

7
1 1 2 2 2 3 3
AAB
ABA
BAA

3*4=12

*/