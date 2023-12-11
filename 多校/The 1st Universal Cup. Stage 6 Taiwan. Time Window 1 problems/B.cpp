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
const int maxn=1e6+100;
vector<int>v[maxn];
int p[maxn];
int n,m,w,cnt;
void dfs(int x)
{
	if(x==n+1)
	{
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			for(auto j:v[i])
			{
				if(p[i]==p[j])flag=0;
			}
		}
		// cnt++;
		cnt+=flag;
		return ;
	}
	for(int i=1;i<=w;i++){
		p[x]=i;
		dfs(x+1);
	}
}
void solve()
{
	cin>>n>>m>>w;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	cout<<cnt<<endl;
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
//ll res = fp(fp(((w-1)*(w-1)-(w-1)+1)%mod,n-1),k)*ans%mod;
/*
12 16 3
5 6
11 1
1 2
2 7
12 4
4 3
3 8
10 9
11 12
5 1
1 4
4 10
6 2
2 3
3 9
7 8
*/
/*
4 4 3
1 2
2 3
3 4
4 1
*/
/*
12 16 3

1 2
2 5
5 6
6 1
2 3
3 7
7 8
8 3
3 4
4 9
9 10
10 4
4 1
1 11
11 12
12 4
648
*/
/*
9 12 3
1 2
2 4
4 5
5 1
2 3
3 6
6 7
7 2
1 3
3 8
8 9
9 1
*/