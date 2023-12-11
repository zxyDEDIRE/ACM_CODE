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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int h[maxn];
int n,d,ans=0;
int fp(int b,int p)
{
	if(h[p])return h[p];
	int r=1,pp=p;
	while(p){
		if(p&1)r=(r*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return h[pp]=r;
}
int f(int i)
{
	int len_1=i;
	int len_2=d-i;
	int ans=0;
	// cout<<"***************"<<endl;
	// cout<<len_1<<" "<<len_2<<endl<<endl;
	for(int j=1;(n-j)>=max(len_1,len_2);j++)
	{
		// cout<<j<<" "<<endl;
		int x=j+len_1;
		int y=j+len_2;
		// cout<<x<<" "<<y<<" "<<endl;
		if(x==y)
		{
			// ans=fp(2,j-1)*fp(2,x-j)*(fp(2,x-j)-1);
			ans+=(((fp(2,j-1)*fp(2,x-j))%mod)*(fp(2,x-j)-1))%mod;
			ans%=mod;
		}
		else
		{
			// cout<<"N"<<endl;
			// cout<<fp(2,j-1)<<" "<<fp(2,x-j)<<" "<<fp(2,y-j)<<endl;
			ans+=(((fp(2,j-1)*fp(2,x-j))%mod)*fp(2,y-j))%mod;
			ans%=mod;
			// ans=fp(2,j-1)*fp(2,x-j)*fp(2,y-j);
		}
		// cout<<ans<<endl;
	}
	// cout<<ans<<endl;
	// cout<<"***************"<<endl;
	return ans;
}
void solve()
{
	cin>>n>>d;
	for(int i=max(0ll,d-n+1);i<=d/2-1;i++)
		ans+=f(i)*2,ans%=mod;
	if(d%2==0)ans+=f(d/2),ans%=mod;
	cout<<ans<<endl;
}
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
1000000 1000000
*/