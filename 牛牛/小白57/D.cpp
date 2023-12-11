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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int p[maxn];
vector<int>v[maxn];
int n;
int ma;
void solve()
{
	cin>>n;
	n=1e3;
	for(int i=1;i<=n;i++)
	{
		// cin>>p[i];
		p[i]=i;
		int x=p[i];
		for(int j=2;j*j<=x;j++)
		{
			if(x%j==0)
			{
				v[j].push_back(p[i]);
				while(x%j==0)x/=j;
			}
		}
		if(x!=1)
			v[x].push_back(p[i]);
	}
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