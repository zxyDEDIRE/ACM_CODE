/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
const int N=3000;
bitset<N>vis;
pii p[N];
int n,d;
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	queue<int>q;
	q.push(1);
	while(!q.empty())
	{
		auto x=q.front();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])continue;
			int dis=(p[i].first-p[x].first)*(p[i].first-p[x].first)+(p[i].second-p[x].second)*(p[i].second-p[x].second);
			if(dis<=d*d)
				q.push(i);
		}
	}
	for(int i=1;i<=n;i++)
		if(vis[i])cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
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