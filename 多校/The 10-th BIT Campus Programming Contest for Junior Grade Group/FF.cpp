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
void doit(int x,int y)
{
	int h=0,w=0,hi=0,fl=mp[x][y];
	for(int i=x;i<=n;i++)
		if(mp[i][y]==fl)h++;
		else break;
	for(int i=y;i<=m;i++)
		if(mp[x][i]==fl)w++,hi=max(hi,H[i]);
		else break;
	int t=x-hi-1;
	// if(t<=0)return ;
	cout<<"h "<<x<<" "<<x+h-1<<endl;
	cout<<"w "<<y<<" "<<y+w-1<<endl;
	cout<<t<<" "<<hi<<endl;
	for(int i=x;i<=x+h-1;i++)
	{
		for(int j=y;j<=y+w-1;j++)
		{
			if(t>0)
			{
				mp[i-t][j]=mp[i][j];
				mp[i][j]=0;
			}
			H[j]=i;
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	int fl=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j])
			{
				doit(i,j);
				fl++;
			}
		}
	}
	cout<<endl;
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