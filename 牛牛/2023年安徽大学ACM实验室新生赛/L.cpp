#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
bool vis[maxn];
int prime[maxn];
void init(int N)
{
	for(int i=2;i<=N;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
bitset<maxn>vi;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	vector<int>v;
	p[n]=1;
	for(int i=2;i;i++){
		if(p[n]*prime[i]>20000)break;
		else v.push_back(prime[i]),p[n]*=prime[i];
	}
	
	vector<int>now;
	for(int i=4;i<=20000;i++)
	{
		if(i==p[n])continue;
		int flag=0;
		for(auto j:v)
			if(i%j==0&&i%2==0){
				flag=1;
				break;
			}
		if(flag)
			now.push_back(i);
		if(now.size()==n)break;
	}
	for(int i=1;i<n;i++)
		p[i]=now[i-1];

	for(int i=1;i<=n;i++)
		cout<<p[i]<<" \n"[i==n];

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init(30000);
		solve();
	return 0;
}
/*
2 2 2 2
        3
        5
        7
        11
  
6*6000
36000
*/