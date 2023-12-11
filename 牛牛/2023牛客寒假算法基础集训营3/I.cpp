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
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
bool vis[maxn];
int prime[maxn];
void init()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=maxn;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
void solve()
{
	int n;cin>>n;
	if(n==1)cout<<2<<endl;
	else if(n==2)cout<<-1<<endl;
	else if(n==3)cout<<4<<endl;
	else if(n==5)cout<<-1<<endl;
	else if(n==7)cout<<8<<endl;
	else if(!(n&1))
	{
		if(!vis[n-1])cout<<(ll)(n-1)*(n-1)<<endl;
		else if(!vis[n-3])cout<<2*(n-3)<<endl;
		else cout<<-1<<endl;
	}
	else
	{
		int flag=1;
		for(int i=1;i<=prime[0];i++)
			if(prime[i]<n-1&&!vis[n-1-prime[i]]&&(n-1-prime[i])!=prime[i])
			{
				cout<<(ll)(prime[i])*(n-1-prime[i])<<endl;
				flag=0;
				break;
			}
		if(flag)
			cout<<-1<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	init();
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 2 4
*/