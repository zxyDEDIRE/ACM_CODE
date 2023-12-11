/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
bitset<maxn>vis;
int num[maxn];
int f[maxn];
int a[maxn];
int n,x,y,p;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void dfs(int now)
{
	vis[now]=1;
	int nxt=(now*x+y)%p;
	int fa=find(now);
	int fb=find(nxt);
	if(fa!=fb){
		f[fa]=fb;
		num[fb]+=num[fa];
	}
	if(!vis[nxt])
		dfs(nxt);
}
void solve()
{
	cin>>n>>x>>y>>p;
	for(int i=0;i<p;i++)
		f[i]=i,num[i]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	for(int i=0;i<p;i++)
	{
		if(vis[i])continue;
		dfs(i);
	}
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=p)continue;
		int fa=find(a[i]%p);
		// if(vis[fa])continue;
		// cout<<fa<<" "<<num[fa]<<endl;
		mp[num[fa]]++;
		// vis[fa]=1;
	}

	// for(int i=0;i<p;i++)
	// {
	// 	cout<<find(i)<<" ";
	// }
	// cout<<endl;
	// for(auto [a,b]:mp)
	// 	cout<<"a b "<<a<<" "<<b<<endl;

	int q;cin>>q;
	while(q--)
	{
		int k;
		cin>>k;
		int cnt=0;
		for(auto [a,b]:mp)
			if(k>=a&&(k%a)==0)
				cnt+=b;
		cout<<cnt<<endl;
	}

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
(2*t+3)%7
3

2 0 3 2 
3 2 0 3
4 4 4 4
5 6 1 5
6 1 5 6 


0 1 2 3 4 5 6
2 6 2 2 4 6 6 2


3 8 4
2 2
3 1 3
4 0 0 0
5 3 

1 2 3 4 5
2 2 3 4 2
2 2 1 4 4
2 2 2 4 2



5 32
2 64
4 64
8 32
16 16


1 1 4 4 1 4
2 2 2 2 2 2

5 32
2 64
4 32
8 16

*/