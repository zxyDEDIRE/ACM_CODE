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
vector<int>v[maxn];
int id[maxn];
int di[maxn];
int p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		v[i].push_back(i);
		p[i]=i;
		id[i]=i;
		di[i]=i;
	}
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x,y;
			cin>>x>>y;
			if(v[id[x]].size()<v[id[y]].size())
			{
				swap(id[x],id[y]);
				swap(di[id[x]],di[id[y]]);
			}
			for(auto i:v[id[y]])
			{
				v[id[x]].push_back(i);
				p[i]=id[x];
			}
			v[id[y]].clear();
		}
		else if(op==2)
		{
			int x;
			cin>>x;
			v[id[x]].push_back(++n);
			p[n]=id[x];
		}
		else if(op==3)
		{
			int x;cin>>x;
			cout<<di[p[x]]<<endl;
		}
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