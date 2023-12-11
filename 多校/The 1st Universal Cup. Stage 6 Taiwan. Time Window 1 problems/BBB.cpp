
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
vector<int>v[maxn];
int p[maxn];
int n,m,w,cnt;
void dfs(int x)
{
	if(x==n*2+1)
	{
		int flag=1;
		for(int i=1;i<=n*2;i++)
		{
			for(auto j:v[i])
			{
				if(p[i]==p[j])flag=0;
			}
		}
		cnt+=flag;
		return ;
	}
	for(int i=1;i<=w;i++){
		p[x]=i;
		dfs(x+1);
	}
}
void solve()
{
	cin>>n>>w;
	for(int i=1;i+2<=n*2;i+=2)
		v[i].push_back(i+2);
	for(int i=2;i+2<=n*2;i+=2)
		v[i].push_back(i+2);
	for(int i=1;i<=n*2;i+=2)
		v[i].push_back(i+1);
	p[1]=1;
	p[2]=2;
	dfs(3);
	cout<<cnt<<endl;
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
/*
(2,2,1)  (3,2,1)  (4,2,1)
(2,3,3)	 (3,3,9)  (4,3,27)
(2,4,7)	 (3,4,49) (4,4,343)
(2,5,13) (3,5,169)


ans = ((w-1)^2 -(w-1)+1)^(n-1)^(k)*f(n,w);
*/