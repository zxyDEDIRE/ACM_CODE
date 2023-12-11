/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
bitset<maxn>vis;
vector<int>v;
int w[maxn];
int p[maxn];
int n,m,tot;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++)
		cin>>p[i];
	for(int i=1;i<=m;i++)
		if(!vis[p[i]])
			v.push_back(p[i]),vis[p[i]]=1;
	reverse(v.begin(),v.end());
	int tot=v.size();
	for(int i=1;i<=m;i++)
		v.push_back(p[i]);
	int ans=0;
	for(int i=tot;i<v.size();i++)
	{
		set<int>s;
		int j=i-1;
		while(v[j]!=v[i]){
			s.insert(v[j]);
			j--;
		}
		int sum=0;
		for(auto i:s)
			sum+=w[i];
		ans+=sum;
		// cout<<i<<" "<<v[i]<<" "<<j<<" "<<sum<<endl;
	}
	cout<<ans<<endl;
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
2
3
1

*/