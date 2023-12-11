/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
ll a[maxn];
ll p[maxn];
ll n;
void solve()
{
	cin>>n;
	int now=1;
	int l=1,r=n;
	while(now<=n)
	{
		p[l++]=now++;
		if(now<=n)p[r--]=now++;
	}
	for(int i=1;i<=n;i++)
		a[i]=p[i];
	for(int j=n-1;j>=1;j--)
	{
		for(int i=1;i<=j;i++)
			p[i]+=p[i+1],p[i]%=mod;
	}
	cout<<p[1]%mod<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
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