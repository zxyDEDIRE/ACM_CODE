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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int k[maxn];
int b[maxn];
int to[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>k[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		cin>>to[i];
	while(m--)
	{
		int x,l,y; 
		cin>>x>>l>>y;
		while(l--)
		{
			// cout<<x<<"->"<<to[x]<<endl;
			x=to[x];
			// cout<<k[x]<<" "<<b[x]<<endl;
			y=k[x]*y%mod+b[x];
			y%=mod;
		}
		cout<<y<<endl;
	}
}
signed main(){
	freopen("in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
给定四个三维向量A1,A2,A3,A4,问是否存在非负实数x1,x2,x3满足
x1A1+x2A2+x3A3=A4
*/