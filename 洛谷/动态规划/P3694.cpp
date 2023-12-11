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
int p[maxn];
vector<int>v[50];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		// cin>>x;
		v[x].push_back(i);
	}
	for(int i=1;i<=m;i++)
		p[i]=i;
	int ans=n;
	int T=0;
	do{
		T++;
		int s,t,num=0;
		s=1;
		for(int i=1;i<=n;i++)
		{
			t=s+v[p[i]].size()-1;
			int len=v[p[i]].size();
			int fl_a=lower_bound(v[p[i]].begin(),v[p[i]].end(),s)-v[p[i]].begin();
			int fl_b=lower_bound(v[p[i]].begin(),v[p[i]].end(),t+1)-v[p[i]].begin();
			num+=len-(fl_b-fl_a);
			s=t+1;
		}
		ans=min(ans,num);
		for(int i=1;i<=n;i++)
			cout<<p[i]<<" ";cout<<endl;
	}while(next_permutation(p+1,p+1+m));
	cout<<ans<<endl;
	cout<<T<<endl;
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