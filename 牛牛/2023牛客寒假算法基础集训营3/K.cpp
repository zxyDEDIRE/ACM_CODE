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
int p[maxn];
int n;
int fp(int b,int p)
{
	int r=1;
	while(p){
		if(p&1)r=(r*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return r;
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
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]>0)cnt++,p[i]--;
	}
	int tot=0;
	for(int i=1;i<=cnt;i++)
		tot=(tot+fp(2,i))%mod;
	// cout<<tot<<endl;

	int a=fp(2,cnt-1);
	int b=fp(2,cnt-2);
	int now=fp(2,cnt);
	int ano=a;
	for(int i=1;i<=n;i++)
	{
		if(!p[i])continue;
		// cout<<tot<<" "<<now<<" "<<a<<" "<<ano<<" "<<b<<endl;

		// for(int j=1;j<=p[i];j++)
		// {
		// 	now+=a;
		// 	tot+=now;
		// 	ano+=b;
		// 	cout<<b<<endl;
		// 	b*=2;
		// }
		// a=ano;

		// tot=tot+(now+a+now+a*p[i])*p[i]/2;
		tot=tot+mull(mull(((now+a+now+a*p[i]%mod)%mod),p[i]),fp(2,mod-2));
		// now=now+a*p[i];
		now=(now+a*p[i]%mod)%mod;
		// ano=ano+b*(fp(b,p[i])-1)*fp(b-1,mod-2)%mod;
		ano=(ano+mull(b,mull((fp(b,p[i])-1+mod)%mod,fp(b-1,mod-2))))%mod;
		// b=b*fp(2,p[i]);
		b=mull(b,fp(2,p[i]));
		a=ano;
		// cout<<(b*(fp(b,p[i])-1)*fp(b-1,mod-2))%mod<<endl;
		// cout<<(fp(b,p[i]))<<endl;
		// cout<<b<<" "<<p[i]<<endl;

		// cout<<tot<<" "<<now<<" "<<a<<" "<<ano<<" "<<b<<endl;
		// cout<<endl;
		tot=tot%mod;
	}
	cout<<tot<<endl;
}//2*(2^1-1)/(2-1)
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
2 3 5 2 3 3
i:1
T:2
Y:1,2
ans:2

i:2
T:6
Y:1,2,3,6
ans:4

i:3
T:30
Y:1,2,3,5,6,10,15,30
1 2 3 5 2*3 2*5 3*5 2*3*5
ans:8

i:4
T:60
Y:1,2,3,4,5,6,10,12,15,20,30,60
1 2 3 2*2 5 2*3 2*5 2*2*3 3*5 2*2*5 2*3*5 2*2*3*5
ans:12
每次加上含2的个数4


18+24
*/