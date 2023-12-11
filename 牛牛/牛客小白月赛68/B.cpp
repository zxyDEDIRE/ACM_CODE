/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
int k[maxn],x[maxn],y[maxn];
void solve()
{
	int n,a,b;
	int mi=INF;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		int k,x,y,v,now;
		cin>>k>>x>>y;
		while(k--)
		{
			cin>>v;
			now=v;
			if(v>=x)now-=y;
			if(v>=a)now-=b;
			mi=min(mi,max(0ll,now));
		}
	}
	cout<<mi<<endl;
}
signed main(){
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