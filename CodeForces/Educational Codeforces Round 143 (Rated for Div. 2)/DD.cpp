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
const int M=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=5e5+100;
const int N=1e5+100;
int ff[maxn];
set<int>s[maxn];
int n;
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
    int c=__gcd(a,b);
    a/=c;
    b/=c;
    Extended_gcd(b,mod);
    x=(x+M)%M;
    x=(x*a)%M;
    return x;
}
int mull(int a,int b)
{
	int qw=0;
	while(b)
	{
		if(b&1)qw=(qw+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return qw;
}
void solve()
{
	cin>>n;
	int ans_1=1;
	for(int i=1;i<=n/3;i++)
	{
		vector<int>v(3,0);
		for(int j=0;j<3;j++)
			cin>>v[j];
		sort(v.begin(),v.end());
		if(v[0]==v[1]&&v[1]==v[2])ans_1=(ans_1*3)%mod;
		else if(v[0]==v[1]&&v[1]!=v[2])ans_1=(ans_1*2)%mod;
	}
	// cout<<ans_1<<endl;
	// cout<<C(n/3,n/6)<<endl;
	cout<<mull(ans_1,C(n/3,n/6))<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	ff[0]=1;
    for(int i=1; i<=N; i++) //预计算n!
        ff[i]=(ff[i-1]*i)%M;
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}