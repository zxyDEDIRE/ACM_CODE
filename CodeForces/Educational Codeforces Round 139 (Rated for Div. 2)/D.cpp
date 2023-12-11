/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e7+100;
bool vis[maxn];
int prime[maxn];
void init()
{
	const int N=1e7;
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
	int x,y;
	cin>>x>>y;
	if(__gcd(x,y)!=1){
		cout<<0<<endl;
		return ;
	}
	if(x>y)swap(x,y);
	vector<int>v;
	int n=y-x;
	for(int i=1;prime[i]*prime[i]<=n&&i<=prime[0];i++)
		if(n%prime[i]==0){
			v.push_back(prime[i]);
			while(n%prime[i]==0)
				n/=prime[i];
		}
	if(n!=1)v.push_back(n);
	int mi=1e9;
	for(auto y:v)
	{
		mi=min(mi,y-x%y);
	}
	if(mi==1e9)cout<<-1<<endl;
	else
	cout<<mi<<endl;
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