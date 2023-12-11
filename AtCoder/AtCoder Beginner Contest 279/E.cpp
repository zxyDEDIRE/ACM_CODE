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
int q[maxn];
int p[maxn];
int t[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>q[i];
		swap(p[q[i]],p[q[i]+1]);
	}
	for(int i=1;i<=m;i++)
		t[p[i]]=i;
	for(int i=1;i<=n;i++)
		p[i]=i;

	for(int i=1;i<=m;i++)
	{
		int x=q[i];
		if(p[x]==1)
			cout<<t[p[x+1]]<<endl;
		else if(p[x+1]==1)
			cout<<t[p[x]]<<endl;
		else cout<<t[1]<<endl;
		swap(p[x],p[x+1]);
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
/*
2 4 3 1 5
*/