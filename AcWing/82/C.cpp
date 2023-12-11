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
int n,m;
void solve()
{
	cin>>n>>m;
	if((m<n-1)||m>2*(n+1)){
		cout<<-1<<endl;
		return ;
	}
	for(int i=1;i<n;i++)
		if(m)p[i]++,m--;
	for(int i=0;i<=n;i++)
		if(m)p[i]++,m--;
	if(m)p[0]++,m--;
	if(m)p[n]++,m--;
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=p[i];j++)
			cout<<"1";
		if(i!=n)
		cout<<0;
	}
	cout<<endl;
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
111011
*/