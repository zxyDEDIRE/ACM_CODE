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
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int a[maxn];
int p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i],a[i]=p[i];
	sort(a+1,a+1+n);
	int del=0;
	while(m)
	{
		int fl=upper_bound(a+1,a+1+n,del)-a;
		int x=a[fl]-del;
		int len=n-fl+1;
		if(x*len>m)
		{
			int len=(n-fl+1);
			int ss=m/len;
			del+=ss;
			m-=len*ss;
			break;
		}
		else
		{
			m-=x*len;
			del+=x;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]<=del)cout<<0<<" ";
		else
		{
			if(m)cout<<p[i]-del-1<<" ",m--;
			else cout<<p[i]-del<<" ";
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}