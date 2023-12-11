/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int a[maxn],b[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	b[n+1]=a[0]=0;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		if(p[i-1]>p[i])a[i]=p[i-1]-p[i];
		else a[i]=0;
		a[i]+=a[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		if(p[i+1]>p[i])b[i]=p[i+1]-p[i];
		else b[i]=0;
		b[i]+=b[i+1];
	}
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		if(x==y)cout<<0<<endl;
		else if(x<y)
		{
			cout<<a[y]-a[x]<<endl;
		}
		else if(x>y)
		{
			cout<<b[y]-b[x]<<endl;
		}

	}

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}