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
	int n;
	cin>>n;
	if(n==1){
		cout<<24<<endl;
		return ;
	}
	int cnt=0;
	int fl=1;
	int ans=1;
	for(int i=1;;i++)
	{
		if(prime[i]-fl<n)continue;
		ans*=prime[i];
		fl=prime[i];
		cnt++;
		if(cnt==3)break;
	}
	cout<<ans<<endl;
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