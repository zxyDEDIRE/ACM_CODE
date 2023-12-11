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
const int maxn=1e6;
int p[maxn];
int ans=0;
int n,k,ma;
int f(int x)
{
	int res=1;
	for(int i=1;i<=n;i++)
	{
		if(x&(1<<(i-1))){
			int yu=k/res;
			if(yu<p[i])return -1;
			res*=p[i];
		}
	}
	return res;
}
void solve()
{
	cin>>n>>k;
	int m=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		int flag=1;
		for(int j=1;j<=m;j++)
		{
			if(p[j]==x)flag=0;
			if(p[j]%x==0)
			{
				p[j]=x;
				flag=0;
			}
			if(x%p[j]==0)flag=0;
		}
		if(flag)p[++m]=x;
	}
	n=m;
	for(int i=1;i<(1<<n);i++)
	{
		int num=__builtin_popcount(i);
		int t=f(i);
		if(t==-1)continue;
		if(num&1)ans+=k/t;
		else ans-=k/t;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 10
2

11 10

1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 2 3


3 10
2 4 6

2 10
2 6

2
4
6
8
10
*/