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
const int maxn=400;
int ans[maxn][maxn];
int mp[maxn][maxn];
int cnt[maxn];
int p[maxn];
set<int>s;
int h,w,tot,n,m,num;

void solve()
{
	cin>>h>>w>>tot>>n>>m;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			cin>>mp[i][j],cnt[mp[i][j]]++,s.insert(mp[i][j]);
	for(int a=1;a+n-1<=h;a++)
	{
		for(int i=1;i<=tot;i++)
			p[i]=0;
		num=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<m;j++){
				p[mp[i+a-1][j]]++;
				if(p[mp[i+a-1][j]]==cnt[mp[i+a-1][j]])
					num++;
			}
		}
		for(int j=1;j+m-1<=w;j++)
		{
			for(int i=1;i<=n;i++)
			{
				p[mp[i+a-1][j+m-1]]++;
				if(p[mp[i+a-1][j+m-1]]==cnt[mp[i+a-1][j+m-1]])num++;
			}
			ans[a][j]=num;
			for(int i=1;i<=n;i++)
			{
				if(p[mp[i+a-1][j]]==cnt[mp[i+a-1][j]])num--;
				p[mp[i+a-1][j]]--;
			}
		}
	}
	for(int i=1;i+n-1<=h;i++)
	{
		for(int j=1;j+m-1<=w;j++)
			cout<<s.size()-ans[i][j]<<" ";
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