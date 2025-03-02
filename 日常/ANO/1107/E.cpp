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
map<string,bool>vis;
int a[10],b[10];
int n,m;
void solve()
{
	cin>>n;
	for(int i=1;i<=n*5;i++)
	{
		string str;
		cin>>str;
		vis[str]=1;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string str;
		int x;
		cin>>str>>x;
		if(vis.count(str))a[x]++;
		else b[x]++;
	}
	int fl=1;
	for(int i=2;i<=5;i++)
		if(a[i]+b[i]<a[fl]+b[fl])fl=i;
	int ans=a[fl];
	for(int i=1;i<=5;i++)
	{
		if(i==fl)continue;
		if(b[i]>a[fl])b[i]-=a[fl];
		else b[i]=0,a[i]-=(a[fl]-b[i]);
	}
	int ma=0;
	for(int i=1;i<=5;i++)
	{
		if(i==fl)continue;
		ma=max(ma,a[i]);
	}
	cout<<ma+ans<<endl;
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