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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=2e6;
int nxt[maxn][3];
int p[maxn];
int indx;
int n;
void insert(bitset<32>&s)
{
	int rt=0;
	for(int i=0;i<32;i++)
	{
		int x=s[i];
		if(!nxt[rt][x])
			nxt[rt][x]=++indx;
		rt=nxt[rt][x];
	}
}
int query(bitset<32>&s)
{
	int rt=0;
	int ans=0;
	for(int i=0;i<32;i++)
	{
		int x=s[i];
		if(nxt[rt][!x])rt=nxt[rt][!x],ans+=(1<<i);
		else rt=nxt[rt][x];
	}
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		p[i]=x;
		bitset<32>vis(x);
		insert(vis);
	}
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		bitset<32>vis(x);
		ma=max(ma,query(vis));
	}
	cout<<ma<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3
8 0 19
*/