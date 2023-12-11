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
vector<int>v[maxn];
int p[maxn];
int cnt=0;
void dfs(int x,int k,int w)
{
	if(x==k+1)
	{
		int flag=1;
		for(int i=1;i<k;i++)
			if(p[i]==p[i+1])
				flag=0;
		if(p[1]==p[k])flag=0;
		cnt+=flag;
		return ;
	}
	for(int i=1;i<=w;i++)
	{
		p[x]=i;
		dfs(x+1,k,w);
	}
}
int solve(int k,int w)
{
	// cin>>k>>w;
	cnt=0;
	dfs(1,k,w);
	// cout<<cnt<<endl;
	return cnt;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	for(int i=2;i<=6;i++)
	{
		for(int j=2;j<=6;j++)
		{
			cout<<"("<<i<<","<<j<<","<<solve(i,j)<<") ";
		}
		cout<<endl;
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
(2,2,2) (2,3,6) (2,4,12) (2,5,20) (2,6,30)
(3,2,0) (3,3,6) (3,4,24) (3,5,60) (3,6,120)
(4,2,2) (4,3,18) (4,4,84) (4,5,260) (4,6,630)
(5,2,0) (5,3,30) (5,4,240) (5,5,1020) (5,6,3120)
(6,2,2) (6,3,66) (6,4,732) (6,5,4100) (6,6,15630)

*/