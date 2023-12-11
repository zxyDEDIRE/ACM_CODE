/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
int p[maxn];
int a[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i]=0,v[i].clear();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		p[x]++;
		p[y]++;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if(m%2==0){
		cout<<0<<endl;
		return ;
	}
	int mi=1e9;
	int ma=1e9;
	for(int i=1;i<=n;i++)
	{
		if(p[i]&1)mi=min(mi,a[i]);
		else
		{
			for(auto y:v[i])
			{
				if((p[y]-1)&1)
				{
					ma=min(ma,a[i]+a[y]);
				}
			}
		}
	}
	cout<<min(mi,ma)<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}