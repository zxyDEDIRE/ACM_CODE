/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
int p[maxn];
int n;
bool ok()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int sum=0;
			for(int k=i;k<=j;k++)
				sum+=p[k];
			if(sum%(j-i+1)==0)return 0;
		}
	}
	return 1;
}
void solve()
{
	cin>>n;
	if(n==1){
		cout<<1<<endl;
		return ;
	}
	if(n&1){
		cout<<-1<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
		if(i%2==0)
			swap(p[i],p[i-1]);
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}