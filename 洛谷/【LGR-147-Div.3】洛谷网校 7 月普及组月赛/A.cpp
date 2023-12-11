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
int p[maxn];
int ans;
int n,m;
void dfs(int x,int step,int mi,int ma)
{
	if(step==m){
		ans=min(ans,ma-mi);
		cout<<ans<<endl;
		return ;
	}
	if(x>n)return ;
	for(int i=x;i<=n;i++)
	{
		int ned = (m-step-1);
		int now = max(0,(ned-1)*2+1);
		int yu=max(0,n-(i+2)+1);
		if(yu<now){
			// cout<<x<<" "<<step<<" "<<ned<<endl;
			// cout<<now<<endl;
			break;
		}
		dfs(i+2,step+1,min(mi,p[i]),max(ma,p[i]));
	}
}
int solve()
{
	cin>>n>>m;
	// n=100,m=n/2;
	if(m==1)return 0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		// p[i]=i;
		// p[i]=T[i];
	}
	ans=INF;
	dfs(1,0,INF,0);
	cout<<ans<<endl;
	return 0;
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
100 43
11451 28255 11021 1888 13765 12592 30989 18758 7833 21591 15085 
13547 11805 31668 23385 18266 30204 6101 22525 22939 13550 20258 
21998 29574 11834 1879 21829 16600 6777 9016 18445 23687 5532 18560 
4191 26195 11824 16922 10699 5790 31201 21139 506 17533 21309 2768 
17554 4623 9403 30972 7770 13070 25852 17349 15263 419 10320 1480 
1494 21887 27516 32073 25730 20775 31675 25640 1368 6543 8194 1040 
28577 11243 26504 23282 26337 17858 16774 25522 24758 4932 16955 22304 
4610 6109 14644 31017 22348 1290 31946 17999 31844 29548 3820 5462 10054 
12827 32543 320 27201 8252

*/