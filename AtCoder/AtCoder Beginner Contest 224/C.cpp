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
pii p[maxn];
int n;
bool S(pii x,pii y,pii z)
{
	double s=0.5*abs((y.first-x.first)*(z.second-x.second)-(z.first-x.first)*(y.second-x.second));
	cout<<s<<endl;
	if(s!=0)return 1;
	return 0;
}
bool ok(int a,int b,int c,int d,int e,int f) //判断三点(a,b)(c,d)(e,f)是否共线
//return 0代表在同一条直线上
{
	if (a != c && c != e && e != a)
	{
		double k1 = 1.0 * (d - b) / (c - a);
		double k2 = 1.0 * (f - d) / (e - c);
		double k3 = 1.0 * (f - b) / (e - a);
		if (k1 == k2 && k2 == k3)
			return 0;
		else
			return 1;
		
	}
	else if (a == c && c == e)
			return 0;
	else
	{
		if (b == d && d == f)
			return 0;
		else
			return 1;
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(S(p[i],p[j],p[k]))
					cnt++;
			}
		}
	}
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


*/