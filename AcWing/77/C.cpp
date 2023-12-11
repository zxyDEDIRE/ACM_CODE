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
bitset<maxn>vis;
int p[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void dfs(int x,int y,int op,int id)
{
	// cout<<x<<" "<<y<<" "<<op<<endl;
	if(x==1&&p[y])return ;
	if(x==1)p[y]=id;
	if(op==1)
	{
		// if(y==1)return ;
		int mi=min(y-1,n-x);
		int xx=x+mi;
		int yy=y-mi;
		// cout<<xx<<" "<<yy<<endl;
		if(xx==n&&yy==1)dfs(xx,yy,4,id);
		else if(xx==n&&yy!=1)dfs(xx,yy,3,id);
		else if(xx!=n&&yy==1)dfs(xx,yy,2,id);
	}
	else if(op==2)
	{
		// if(y==m)return ;
		int mi=min(n-x,m-y);
		int xx=x+mi;
		int yy=y+mi;
		// cout<<xx<<" "<<yy<<endl;
		if(xx==n&&yy==m)dfs(xx,yy,3,id);
		else if(xx==n&&yy!=m)dfs(xx,yy,4,id);
		else if(xx!=n&&yy==m)dfs(xx,yy,1,id);
	}
	else if(op==3)
	{
		// if(y==1)return ;
		int mi=min(y-1,x-1);
		int xx=x-mi;
		int yy=y-mi;
		// cout<<xx<<" "<<yy<<endl;
		if(xx==1&&yy==1)dfs(xx,yy,2,id);
		else if(xx==1&&yy!=1)dfs(xx,yy,1,id);
		else if(xx!=1&&yy==1)dfs(xx,yy,4,id);
	}
	else if(op==4)
	{
		// if(y==m)return ;
		int mi=min(x-1,m-y);
		int xx=x-mi;
		int yy=y+mi;
		// cout<<xx<<" "<<yy<<endl;
		if(xx==1&&yy==m)dfs(xx,yy,1,id);
		else if(xx==1&&yy!=m)dfs(xx,yy,2,id);
		else if(xx!=1&&yy==m)dfs(xx,yy,3,id);
	}
}
void solve()
{
	cin>>n>>m;
	if(n>m)swap(n,m);
	int cnt=0;
	// cout<<n<<" "<<m<<endl; 
	for(int i=1;i<=m;i++)
	{
		if(p[i])continue;
		cnt++;
		if(i>1)
			dfs(2,i-1,1,cnt);
		if(i<m)
			dfs(2,i+1,2,cnt);
		p[i]=cnt;
		// cout<<endl;
		// break;
	}
	cout<<cnt<<endl;
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