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
int mp[maxn];
void init(int N)
{
	for(int i=2;i<=N;i++)
	{
		if(!vis[i])prime[++prime[0]]=i,mp[i]=prime[0];
		for(int j=1;j<=prime[0]&&prime[j]*i<=N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
int T=80000;
int f[maxn];
int p[maxn];
int n;
int find(int r){
	return f[r]=(f[r]==r?f[r]:find(f[r]));
}
void merge(int x,int y){
	int fa=find(x);
	int fb=find(y);
	if(fa!=fb)f[fa]=fb;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n+T;i++)
		f[i]=i;
	int T=-1;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		p[i]=x;
		if(x==1)
			continue;
		T=i;
		for(int j=2;j*j<=x;j++)
			if(x%j==0){
				merge(i,n+mp[j]);
				while(x%j==0)
					x/=j;
			}
		if(x!=1)merge(i,n+mp[x]);
	}
	vector<int>a,b;
	for(int i=1;i<=n;i++)
	{
		if(T!=-1 && find(i)==find(T))a.push_back(p[i]);
		else b.push_back(p[i]);
	}
	if(a.size()==0 && b.back()==1)
		a.push_back(1),b.pop_back();

	if(b.size()==0){
		cout<<"-1 -1\n";
		return ;
	}
	cout<<a.size()<<" "<<b.size()<<endl;
	for(auto i:a)
		cout<<i<<" ";
	cout<<endl;
	for(auto i:b)
		cout<<i<<" ";
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init(1e6);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}