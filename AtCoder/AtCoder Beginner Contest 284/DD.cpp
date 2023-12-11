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
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=4e6+100;
int prime[maxn];
bool vis[maxn];
int n,wer=3e6+10;
void init()
{
	int N=4e6+10;
	for(int i=2;i<=N;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
void solve()
{
	cin>>n;
	int m=min(wer,n);
	for(int i=1;prime[i]<=m&&i<=prime[0];i++)
	{
		int x=prime[i];
		if(n%(x*x)==0)
		{
			cout<<x<<" "<<n/x/x<<endl;
			return ;
		}
	}
	for(int i=2;i<=m;i++){
		if(n%i)continue;
		int t=n/i;
		int sq=sqrt(t);
		if(sq*sq==t){
			cout<<sq<<" "<<i<<endl;
			return;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3000000

*/