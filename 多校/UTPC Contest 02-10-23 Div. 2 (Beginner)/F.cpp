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
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=4e6+100;
bool vis[maxn];
int prime[maxn];
ll t[maxn];
void init(int MAX)
{
	for(int i=2;i<=MAX;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=MAX;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
void solve()
{
	int n;
	cin>>n;
	init(n);
	for(int i=1;i<=prime[0];i++){
		cout<<prime[i]<<endl;
		for(int j=1,k=prime[i];k<=n;j++,k+=prime[i])
			t[k]+=j,cout<<k<<" ";
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
		cout<<t[i]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;ci.-)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}