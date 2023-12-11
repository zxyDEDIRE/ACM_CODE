/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
bitset<maxn>vis;
map<int,int>mp;
int p[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i;
	int tot=n+m;
	for(int i=1;i<=m;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x,y;
			cin>>x>>y;
			p[x]=y;
			vis[x]=1;
		}
		else if(op==2)
		{
			int x;cin>>x;
			++n;
			p[n]=n;
			if(vis[x])
			{
				tot++;
				p[x]=tot;
				mp[tot]=x;
			}
			else
			{
				p[n]=x;
			}
		}
		else if(op==3)
		{
			int x;cin>>x;
			cout<<p[x]<<endl;
		}
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