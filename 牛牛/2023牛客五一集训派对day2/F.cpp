/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=5e3+10;
int p[N][N];
int a[N][N];
int b[N][N];
int n,m,k;
int q[maxn],s,t;
void solve()
{
	cin>>n>>m>>k;
	ll S=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			p[i][j]=(i*j/__gcd(i,j));
			S+=p[i][j];
		}
	cout<<S<<endl;
	// for(int i=1;i<=n;i++)
	// {
	// 	s=0,t=-1;
	// 	for(int j=1;j<=m;j++)
	// 	{
	// 		if(s<=t&&q[s]<p[i][j])
	// 			s++;

	// 	}
	// }


	for(int i=1;i<=n;i++)
	{
		multiset<int>s;
		for(int j=1,r=1;j+k-1<=m;j++)
		{
			while(r<=j+k-1){
				s.insert(p[i][r]);
				r++;
			}
			a[i][j]=*s.rbegin();
			s.erase(s.find(p[i][j]));
		}
	}
	for(int j=1;j+k-1<=m;j++)
	{
		multiset<int>s;
		for(int i=1,r=1;i+k-1<=n;i++)
		{
			while(r<=i+k-1){
				s.insert(a[r][j]);
				r++;
			}
			b[i][j]=*s.rbegin();
			s.erase(s.find(a[i][j]));
		}
	}
	ll sum=0;
	for(int i=1;i+k-1<=n;i++)
		for(int j=1;j+k-1<=m;j++)
			sum+=1ll*b[i][j];
	cout<<sum<<endl;
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
/*

*/