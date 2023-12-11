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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int a[maxn],b[maxn];
vector<pii>v[maxn];
int in[maxn];
int p[maxn];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		p[x]+=y;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		v[y].push_back({x,c});
		in[x]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i]){
			q.push(i);
		}
	int ans=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		(ans+=p[x])%=mod;
		for(auto [y,c]:v[x])
		{
			(p[y]+=p[x]*c)%=mod;
			in[y]--;
			if(!in[y])
				q.push(y);
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
2*2+2
2
4*2+2
*/