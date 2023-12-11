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
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
ll p[maxn];
ll q[maxn];
ll n,m,T;
void solve()
{
	cin>>n>>m>>T;
	for(int i=1;i<n;i++)
		cin>>p[i];
	for(int i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		q[x]+=y;
	}
	for(int i=1;i<n;i++) 
	{
		T-=p[i];
		T+=q[i];
		if(T<=0)
		{
			cout<<"No"<<endl;
			return ;
		}
	}
	cout<<"Yes"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}