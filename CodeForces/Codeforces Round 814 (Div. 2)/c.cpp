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
int t[maxn];
int p[maxn];
int n,q;
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i],t[i]=0;
	int s=1;
	for(int i=2;i<=n;i++)
	{
		if(p[i]>p[s])s=i,t[s]++;
		else t[s]++;
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(y<=n)
		{
			cout<<min(t[x],y-x+2)<<endl;
		}
		else
		{
			if(p[x]==n)cout<<t[x]+(y-n)+1<<endl;
			else cout<<t[x]<<endl;
		}
	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 4 5 6
*/