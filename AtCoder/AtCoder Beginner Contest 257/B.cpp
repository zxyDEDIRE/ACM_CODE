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
int t[maxn];
int p[maxn];
int n,k,q;
void solve()
{
	cin>>n>>k>>q;
	for(int i=1;i<=k;i++)
	{
		int x;cin>>x;
		p[x]=1;
		t[i]=x;
	}
	for(int i=1;i<=q;i++)
	{
		int a;cin>>a;
		int x=t[a];
		if(x==n)continue;
		if(p[x+1])continue;
		p[x]=0,p[x+1]=1;
		t[a]=x+1;
	}
	for(int i=1;i<=k;i++)
		cout<<t[i]<<" ";cout<<endl;
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