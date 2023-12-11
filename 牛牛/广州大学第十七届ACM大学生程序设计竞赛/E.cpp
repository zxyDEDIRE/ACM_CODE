/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
int more[maxn];
pii p[maxn];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int t=1;t<=m;t++)
	{
		int op,i;
		cin>>op>>i;
		if(op==1)
		{
			auto [x,y]=p[i];
			more[i]+=min(y,t-x);
			p[i]={t,k};
		}
		else if(op==2)
		{
			auto [x,y]=p[i];
			more[i]+=min(y,t-x);
			p[i]={t,0};
		}
		else if(op==3)
		{
			auto [x,y]=p[i];
			cout<<more[i]+t-1+min(y,t-x)<<endl;
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