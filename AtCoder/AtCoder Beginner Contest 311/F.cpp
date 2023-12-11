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
const int N=333;
int mp[N][N];
int s[N][N];
int n,m;
struct ST{
	int f[309][309][9][9];
	void init(int m,int n)
	{

		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				f[i][j][0][0]=mp[i][j];

		int t=log(n)/log(2)+1;//j定位 
		for(int i=0;i<=t;i++)
	    {
	        for(int j=0;j<=t;j++)
	        {
	            if(i==0&&j==0)
	                continue;
	            for(int row=1;row+(1<<i)-1<=m;row++)
	            {
	                for(int col=1;col+(1<<j)-1<=n;col++)
	                {
	                    if(i)f[row][col][i][j]=min(f[row][col][i-1][j],f[row+(1<<(i-1))][col][i-1][j]);
	                    else f[row][col][i][j]=min(f[row][col][i][j-1],f[row][col+(1<<(j-1))][i][j-1]);
	                }
	            }
	        }
	    }
	}
	int query(int x1,int y1,int x2,int y2)
	{
	    int k1 = log(double(x2 - x1 + 1)) / log(2.0);
	    int k2 = log(double(y2 - y1 + 1)) / log(2.0);
	    int m1 = f[x1][y1][k1][k2];
	    int m2 = f[x2 - (1<<k1) + 1][y1][k1][k2];
	    int m3 = f[x1][y2 - (1<<k2) + 1][k1][k2];
	    int m4 = f[x2 - (1<<k1) + 1][y2 - (1<<k2) + 1 ][k1][k2];
	    int _max = min(min(m1,m2),min(m3,m4));
	    return _max;
	}
}st;
int get(int x1,int y1,int x2,int y2)
{
	return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}
void solve()
{
	cin>>n>>m;
	// n=300;m=300;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
			// mp[i][j]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mp[i][j];
		}
	st.init(n,m);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int _i=i;_i<=n;_i++)
			{
				for(int _j=j;_j<=m;_j++)
				{
					ans=max(ans,get(i,j,_i,_j)*st.query(i,j,_i,_j));
				}
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		clock_t start, finish;
	start = clock();
	/*******代码*******/
	solve();
	/****************/
	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}