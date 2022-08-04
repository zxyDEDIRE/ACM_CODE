/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int p[maxn];
int n,v;
void solve()
{
	cin>>n;
	v=0;
	for(int i=1;i<=n;i++)
	{
		v+=i*(n-i+1);
		p[i]=n-i+1;
	}
	int tmp=sqrt(v);
	for(int ii=tmp;ii>=1;ii--)
	{
		if(v%ii==0)
		{
			int y=v/ii;
			int x=ii;
			cout<<x*2+y*2<<endl;
			for(int i=1;i<=x;i++)
			{
				int len=0;

					for(int j=n;j>=1;j--)
					{
						while(len+j<=y&&p[j])
						{
							cout<<len<<" "<<i-1<<" "<<len+j<<" "<<i<<endl;
							len+=j;
							p[j]--;
						}
					}
			}
			break;
		}
	}
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}