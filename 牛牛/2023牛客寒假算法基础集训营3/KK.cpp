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
const int maxn=3e6+100;
int prime[maxn],phi[maxn];
bool vis[maxn];
void doit()
{
	for(int i=2;i<=maxn-1;i++){
		if(!vis[i])prime[++prime[0]]=i,phi[i]=i-1;
		for(int j=1;j<=prime[0]&&prime[j]*i<=maxn;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int t=1;
	for(int i=1;i<=n;i++)
	{
		t*=p[i];
		int ans=0;
		for(int j=1;j<=t;j++)
			if(t%j==0)
				ans++;
		cout<<ans<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	doit();
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
2 3 2
2 6 12 24
1 2-2
1 2 3 6-4
1 2 3 4 6 12 -6
1 2 3 4 6 8 12 24 -8

2 2
3 4
4 8
*/