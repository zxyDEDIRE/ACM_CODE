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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int c[maxn];
int yu[maxn];
int n,x;
void solve()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++){
		yu[i]=c[i]%x;
		c[i]-=yu[i];
		if(c[i]==0){
			cout<<-1<<endl;
			return ;
		}
	}
	for(int i=2;i<=n;i++)
		if(yu[i]!=yu[1]){
			cout<<-1<<endl;
			return ;
		}
	int mi=1e18+10 ;
	for(int i=1;i<=n;i++)
	{
		mi=min(mi,c[i]-x);
	}
	cout<<mi+yu[1]<<endl;
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