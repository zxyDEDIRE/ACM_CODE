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
int p[maxn];
int t[maxn];
int n;
int c(int x,int y)
{
	int a=1,b=1;
	for(int i=1,t=y;i<=t;i++)
	{
		a*=x;x--;
		b*=y;y--;
	}
	return a/b;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],t[p[i]]++;
	int ans=c(n,3);
	// cout<<ans<<endl;
	// cout<<endl;
	for(int i=1;i<maxn;i++)
		if(t[i]>1)
		{
			ans-=c(t[i],2)*(n-t[i]);
			if(t[i]>2)
				ans-=c(t[i],3);
		}
	// cout<<endl;
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