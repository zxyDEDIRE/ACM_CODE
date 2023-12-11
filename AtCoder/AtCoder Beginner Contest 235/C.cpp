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
map<int,int>mp;
vector<int>v[maxn];
int n,q,tot;
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(!mp.count(p[i]))
			mp[p[i]]=++tot;
		v[mp[p[i]]].push_back(i);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(y<=v[mp[x]].size())cout<<v[mp[x]][y-1]<<endl;
		else cout<<-1<<endl;
	}
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