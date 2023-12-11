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
const int N=3333;
int mp[N][N];
int s[N][N];
int n,m,k;
int get(int x1,int y1,int x2,int y2)
{
	return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[x][y]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mp[i][j];
		}
	long long res=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int len=min(n-i+1,m-j+1);

			int l=0,r=len,ans=0;
			while(l<r-1)
			{
				int mid=(l+r)>>1;
				if(!get(i,j,i+mid-1,j+mid-1))ans=mid,l=mid;
				else r=mid;
			}
			while(ans<len&&!get(i,j,i+ans,j+ans))ans++;

			res+=ans;
		}
	}
	cout<<res<<endl;
}

signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	// 	clock_t start, finish;
	// start = clock();
	/*******代码*******/
	solve();
	/****************/
	// finish = clock();
	// cout << "the time cost is" <<\
	// double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}