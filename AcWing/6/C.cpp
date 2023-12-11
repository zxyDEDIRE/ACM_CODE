/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int mp[30][30];
int p[30][30];
int vis[30];
int q[30];
int n,m,fl=1,out;
void dfs(int s,int x,int t)
{
	if(out)return ;
	if(x>t)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				p[i][j]=mp[i][j];
		for(int ii=1;ii<=t;ii++)
		{
			int x=q[ii];
			vector<int>u;
			for(int i=1;i<=n;i++)
				if(p[x][i])
					u.push_back(i);
			for(int i=0;i<u.size()-1;i++)
			{
				for(int j=i+1;j<u.size();j++)
				{
					p[u[i]][u[j]]=p[u[j]][u[i]]=1;
				}
			}
		}
		int flag=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(!p[i][j]){
					flag=0;
					break;
				}
		if(flag){
			fl=0;
			out=1;
			cout<<t<<endl;
			for(int i=1;i<=t;i++)
				cout<<q[i]<<" ";
			cout<<endl;
		}	
		return ;
	}
	for(int i=s;i<=n;i++)
	{
		q[x]=i;
		dfs(i+1,x+1,t);
	}
}
void solve()
{
	cin>>n>>m;
	if(m==0){
		cout<<0<<endl;
		return ;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[x][y]=mp[y][x]=1;
	}
	for(int i=1;i<=n;i++)
		mp[i][i]=1;
	while(fl)
		dfs(1,1,fl++);
}
signed main(){
// freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
// freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
// int __;cin>>__;
// while(__--)
	clock_t start, finish;
	start = clock();
	solve();
	finish = clock();
	 cout << "the time cost is " << double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}