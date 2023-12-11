#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=100;
ll mp[maxn][maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	ll ma=-1e10,x=0,y=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			if(mp[i][j]>ma)
			{
				ma=mp[i][j];
				x=i;
				y=j;
			}
		}
	}
	int a=max(x,n-x+1);
	int b=max(y,m-y+1);
	cout<<a*b<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}