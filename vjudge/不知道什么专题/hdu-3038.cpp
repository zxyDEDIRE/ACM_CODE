/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dep[maxn];
int p[maxn];
int n,m;
void init()
{
	for(int i=0;i<=n;i++)
		p[i]=i,dep[i]=0;
}
int find(int r)
{
	if(p[r]==r)return p[r];
	int tmp=find(p[r]);
	dep[r]+=dep[p[r]];
	return p[r]=tmp;
}
void solve()
{
	while(cin>>n>>m)
	{
		init();
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int x,y,w;
			cin>>x>>y>>w;
			x--;
			int fa=find(x);
			int fb=find(y);
			if(fa!=fb)
			{
				p[fa]=fb;
				dep[fa]=w+dep[y]-dep[x];
			}
			else if(dep[x]-dep[y]!=w)
				ans++;
		}
		cout<<ans<<endl;
		break;
	}
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
/*
4
1 3 4 2
4 3 2 1

1 3 4 2
1 3 2 4
*/