/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
vector<int>v[maxn];
int n,tot;
void solve()
{
	cin>>n;
	vector<pii>p(n);
	for(auto &[x,y]:p)
		cin>>x>>y;
	sort(p.begin(),p.end());
	int tot=0;
	for(int i=0;i<n;i++)
	{
		if(i==0||p[i].first!=p[i-1].first)
			tot++;
		v[tot].push_back(p[i].second);
	}
	vector<map<int,bool>>mp(n+1);
	for(int i=1;i<=tot;i++)
		for(auto y:v[i])
			mp[i][y]=1;
	int ans=0;
	for(int x=1;x<tot;x++)
	{
		for(int i=0;i<v[x].size();i++)
		{
			for(int j=i+1;j<v[x].size();j++)
			{
				for(int y=x+1;y<=tot;y++)
					if(mp[y].count(v[x][i])&&mp[y].count(v[x][j]))
						ans++;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}