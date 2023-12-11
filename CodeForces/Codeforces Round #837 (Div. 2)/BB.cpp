#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N=1e6+7;
const int INF=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
const int maxn=1e6;
bool vis[maxn];
int prime[maxn];
void init()
{
	int N=1e5;
	for(int i=2;i<=N;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
set<int>se;
void solve()
{
	int n;
	cin>>n;
	se.clear();
	int fl=0;
	while(n--){
		int x;
		cin>>x;
		for(int i=1;i<=prime[0]&&prime[i]*prime[i]<=x;i++){
			if(x%prime[i]==0){
				if(se.count(prime[i]))fl=1;
				else se.insert(prime[i]);
				while(x%prime[i]==0)x/=prime[i];
			}
			
		}
		if(se.count(x)&&x!=1)fl=1;
		else se.insert(x);
	}
	cout<<(fl?"YES":"NO")<<endl;
}
signed main()
{
	IOS
	init();
	int __=1;
	cin >> __;
	while (__--)
		solve();
}