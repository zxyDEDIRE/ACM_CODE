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
const int maxn=1e6+100;
vector<int>v[maxn];
int cnt[maxn];
int in[maxn];
pii p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>p[i].first>>p[i].second;
		in[p[i].first]++;
		in[p[i].second]++;
	}
	for(int i=1;i<=m;i++)
	{
		int x=p[i].first;
		int y=p[i].second;
		if(in[x]<in[y])swap(x,y);
		else if(in[x]==in[y]&&x>y)swap(x,y);
		v[x].push_back(y);
	}
	int ans=0;
	for(int x=1;x<=n;x++)
	{
		for(auto y:v[x])cnt[y]++;
		for(auto y:v[x])
			for(auto z:v[y])
				ans+=cnt[z];
		for(auto y:v[x])cnt[y]=0;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}