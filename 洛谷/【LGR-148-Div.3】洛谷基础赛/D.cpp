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
bool vis[maxn];
int p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int mi=INF;
	for(int i=1;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)<k)continue;
		for(int j=0;j<n;j++)
			if(i&(1<<j))vis[j+1]=1;
			else vis[j+1]=0;

		// for(int j=1;j<=n;j++)
			// cout<<vis[j]<<" ";cout<<endl;

		int now=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]){
				now+=p[j]*p[j];
				continue;
			}
			int l=j,_l=0;
			int r=j,_r=0;
			while(!vis[l]){
				l--;_l++;
				if(l==0)l=n;
			}
			while(!vis[r]){
				r++;_r++;
				if(r==n+1)r=1;
			}
			// cout<<j<<" "<<l<<" "<<r<<endl;
			if(p[l]>p[r])now+=_l*p[l];
			else now+=_r*p[r];
		}
		mi=min(mi,now);
		// break;
	}
	cout<<mi<<endl;
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
1 2 3
*/