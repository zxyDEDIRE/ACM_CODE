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
int ans[maxn];
int sum[maxn];
vector<pii>v;
int a[maxn];
int p[maxn];
int n,Q;
void solve()
{
	cin>>n>>Q;
	priority_queue<int>q;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		q.push(p[i]);
	}
	int now=0;
	while(1)
	{
		int x=q.top();q.pop();
		ans[now++]=x;
		if(x==1)break;
		x=__builtin_popcount(x);
		q.push(x);
	}
	while(Q--)
	{
		int x;cin>>x;
		if(x>=now)cout<<1<<endl;
		else cout<<ans[x]<<endl;
	}


}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
// 10 12 13 14 15 16 17 18 19