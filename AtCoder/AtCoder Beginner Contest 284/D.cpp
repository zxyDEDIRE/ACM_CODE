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
const int maxn=5e6+100;
int n;
bool vis[maxn];
int prime[maxn];
void init()
{
	vis[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=maxn;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
	cout<<"ok"<<endl;
}
void solve()
{
	// cin>>n;
	n=9e18;
	for(int i=1;i<=prime[0]&&prime[i]*prime[i]<n;i++)
	{
		if(n%prime[i]==0)
		{
			int x=prime[i]*prime[i];
			if(n%x==0&&!vis[n/x]){
				cout<<prime[i]<<" "<<n/x<<endl;
				return ;
			}
			int y=sqrt(n/prime[i]);
			if(!vis[y]&&y*y==(n/prime[i])){
				cout<<y<<" "<<prime[i]<<endl;
				return ;
			}
		}
	}
	cout<<"Yes"<<endl;
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
*/