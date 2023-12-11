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
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n,fl;
void dfs(int x)
{
	// if(fl)return ;
	if(x>n)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=p[i];
		int flag=1;
		for(int i=1;i<n;i++)
			if(p[i]+p[i+1]!=sum)
				flag=0;
		if(flag){
			fl=1;
			cout<<sum<<endl;
			for(int i=1;i<=n;i++)
				cout<<p[i]<<" ";
			cout<<endl;;
		}
		return ;
	}
	for(int i=-14;i<=14;i++)
	{
		if(i==0)continue;
		p[x]=i;
		dfs(x+1);
	}
}
void solve()
{
	cin>>n;
	dfs(1);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		// solve();
	int n=999;
	cin>>n;
	int x=n/2-1;
	int y=n/2;
	cout<<(-x+y)<<endl;
	cout<<(-x*(n/2+1)+y*(n/2))<<endl;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
28-42
4*7 3*2*7
7 -14 7 -14 7 -14 7
*/