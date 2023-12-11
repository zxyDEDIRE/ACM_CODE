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
int p[111][4];
int n;
bool check(int x)
{
	if(x==n)return 1;
	if(p[x][1]==0&&p[x][2]==0)return 0;
	if(p[x][3]==0&&p[x][2]==0)return 0;
	if(p[x][1]==p[x][2]&&p[x][2]==p[x][3]&&p[x][1]==0)return 0;
	return 1;
}
void solve()
{
	cin>>n;
	memset(p,1,sizeof(p));
	for(int i=1;i<=n*3-3;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		p[x][y]=0;
		if(!check(x))
		{
			if(i&1)cout<<"Nocriz"<<endl;
			else cout<<"Sheauhaw"<<endl;
			return ;
		}
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