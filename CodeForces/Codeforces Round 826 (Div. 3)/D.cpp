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
int p[maxn];
int n,flag,ans;
void dfs(int l,int r,int numl,int numr)
{
	if(l==r)return ;
	if(flag)return ;
	int mid_num=(numl+numr)>>1;
	int mid=(l+r)>>1;

	int fl=0;
	if(p[l]>mid_num)fl=1;

	for(int i=l;i<=r;i++)
	{
		if(i<=mid)
		{
			if(p[i]<=mid_num&&fl)flag=1;
			if(p[i]>mid_num&&!fl)flag=1;
		}
		else
		{
			if(p[i]<=mid_num&&!fl)flag=1;
			if(p[i]>mid_num&&fl)flag=1;
		}
	}
	ans+=fl;
	if(fl==0)
	{
		dfs(l,mid,numl,mid_num);
		dfs(mid+1,r,mid_num+1,numr);
	}
	else if(fl==1)
	{
		dfs(l,mid,mid_num+1,numr);
		dfs(mid+1,r,numl,mid_num);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	ans=flag=0;
	dfs(1,n,1,n);
	if(flag)cout<<-1<<endl;
	else cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}