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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=50;
vector<int>v[maxn];
bitset<maxn>vis;
int s[maxn];
int cnt;
int n,m;
bool check(int x,int y){
	for(auto i:v[x])
		if(i==y)return 1;
	return 0;
}
void dfs(int x,int step,int t)
{
	// if(vis[x])return ;
	s[step]=x;
	// vis[x]=1;
	if(step==20)
	{
		if(check(x,t))
		{
			cout<<++cnt<<":  ";
			for(int i=1;i<=20;i++)
				cout<<s[i]<<" ";
			cout<<t<<endl;
		}
		return ;
	}
	for(auto y:v[x])
	{
		if(vis[y])continue;
		vis[y]=1;
		dfs(y,step+1,t);
		vis[y]=0;
	}

}
void solve()
{
	n=20;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[i].push_back(a);
		v[i].push_back(b);
		v[i].push_back(c);
		// v[a].push_back(i);
		// v[b].push_back(i);
		// v[c].push_back(i);
		sort(v[i].begin(),v[i].end());
	}
	while(cin>>m&&m){
		cnt=0;
		vis[m]=1;
		dfs(m,1,m);
		vis[m]=0;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	// clock_t start, finish;
	// start = clock();
		solve();
	// 	finish = clock();
	// cout << "the time cost is" <<\
	// double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1:  5 1 2 3 4 8 7 17 18 14 15 16 9 10 11 12 13 20 19 6 5
1:  5 1 2 3 4 8 7 17 18 14 15 16 9 10 11 12 13 20 19 6 5
*/