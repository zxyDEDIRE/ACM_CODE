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
vector<int>v[maxn];
string str;
int p[maxn];
int a[maxn];
int n;
int dfs(int x)
{
	int sum=1;
	for(auto y:v[x])
	{
		sum+=dfs(y);
	}
	if(str[x-1]=='R')
	{
		sum%=3;
		if(sum!=0)a[x]=3-sum;
		sum=0;
	}
	return sum;
}
void dfs2(int x,int f)
{
	if(str[x-1]=='R')f=x;

	if(a[f])
	{
		p[x]++;
		a[f]--;
	}

	for(auto y:v[x])
		dfs2(y,f);
}
void solve()
{
	cin>>n>>str;
	for(int i=2;i<=n;i++){
		int x;cin>>x;
		v[x].push_back(i);
	}
	int sum = dfs(1);
	if(str[0]=='R')
	{
		sum%=3;
		if(sum!=0)a[1]=3-sum;
	}
	dfs2(1,1);
	for(int i=1;i<=n;i++)
		if(a[i]){
			cout<<-1<<endl;
			return ;
		}
	for(int i=1;i<=n;i++)
		cout<<p[i]+1;
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*

*/