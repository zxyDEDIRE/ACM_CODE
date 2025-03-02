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
#define nullptr 0
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=300;
int s[maxn];
int p[maxn];
int t[maxn];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
bool dfs(int w,int step=1)
{
	if(step>n)return false;
	if(abs(w)>s[step])
		return false;
	if(w==0||abs(w)==s[step])
		return true;
	if(dfs(w,step+1)||dfs(w+p[step],step+1)||dfs(w-p[step],step+1))
		return true;
	else return false;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n,cmp);
	for(int i=n;i>=1;i--)
		s[i]=p[i]+s[i+1];
	for(int i=1;i<=m;i++)
	{
		int x;cin>>x;
		if(dfs(x))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
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