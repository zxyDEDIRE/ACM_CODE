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
int p[maxn];
int x,y;
void solve()
{
	cin>>x>>y;
	if(x>y)swap(x,y);
	int fl;
	int xx=x;
	int t=2;
	for(int i=1;i<=29;i++)
	{
		if(xx<=p[i])break;
		xx-=p[i];
		t*=2;
	}
	fl=t-xx+1;
	int yu=y-x+1;
	if(yu<=fl)cout<<"Bob"<<endl;
	else cout<<"Alice"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int t=2,sum=0;
	for(int i=1;i;i++)
	{
		p[i]=t;
		sum+=p[i];
		// cout<<p[i]<<" "<<sum<<" "<<i<<endl;
		if(sum>1e9)break;
		t*=2;
	}
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
1 前2个必败
2 前1个必败
3 前4个必败
4 前3个必败
5 前2个必败
6 前1个必败
7 前8个必败
8 前7个必败
9 前6个必败
10 前5个必败
