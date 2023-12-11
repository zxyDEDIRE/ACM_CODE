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
const int maxn=1e3+100;
int mp[maxn][maxn];
int H[maxn];
int n,m;
int get_h(int x,int y){
	int ans=0;
	for(int i=x;i<=n;i++)
		if(mp[i][y]==mp[x][y])ans++;
	else break;
	return ans;
}
int get_w(int x,int y){
	int ans=0;
	for(int i=y;i<=m;i++)
		if(mp[x][i]==mp[x][y])ans++;
	else break;
	return ans;
}
int get_hi(int y,int w)
{
	int ma=0;
	for(int i=y;i<=y+w-1;i++)
		ma=max(ma,H[i]);
	return ma;
}
void doit(int x,int y)
{	
	int h=get_h(x,y);
	int w=get_w(x,y);
	int hi=get_hi(y,w);
	int t=x-hi-1;
	// cout<<x<<" "<<y<<" "<<h<<" "<<w<<" "<<hi<<" "<<t<<endl;
	for(int i=x;i<=x+h-1;i++)
	{
		for(int j=y;j<=y+w-1;j++)
		{
			if(t)
			{
				mp[i-t][j]=mp[i][j];
				mp[i][j]=0;
			}
			H[j]=max(H[j],i-t);
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]&&H[j]<i)
				doit(i,j);
		}
	}
	// cout<<endl;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
			cout<<mp[i][j]<<" ";
		cout<<endl;
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