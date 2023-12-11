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
vector<pii>ans;
vector<pii>v;
vector<pii>u;
int p[maxn];
int n;
void f(int l,int r)
{
	for(int i=l;i<=r;i+=2)
	{
		int x=p[i];
		int y=p[i+1];
		if(x+y!=0)
			ans.push_back({i,i+1});
		else ans.push_back({i,i}),ans.push_back({i+1,i+1});
	}
}
void solve()
{
	u.clear();
	v.clear();
	ans.clear();
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=n;i>=1;i--)
	{
		if(p[i]!=0)
		{
			if(p[i]+p[i-1]==0)
				ans.push_back({i,i}),ans.push_back({i-1,i-1});
			else if(p[i-1]!=0)
				ans.push_back({i-1,i});
			else if(p[i-1]==0)
				v.push_back({i-1,i});
			i--;
		}
		else ans.push_back({i,i});
	}
	if(v.size()&1)cout<<-1<<endl;
	else
	{
		int a=0;
		for(auto [l,r]:v)
			a+=p[r];
		for(auto [l,r]:v)
		{
			if(p[r]>0&&r<=n&&a>0)
			{
				a-=2;
				ans.push_back({l,r});
			}
			else if(p[r]<0&&r<=n&&a<0)
			{
				a+=2;
				ans.push_back({l,r});
			}
			else
			{
				if(l)ans.push_back({l,l});
				if(r)ans.push_back({r,r});
			}
		}
		sort(ans.begin(),ans.end());

		cout<<ans.size()<<endl;
		for(auto [l,r]:ans)
			cout<<l<<" "<<r<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
1
5
0 -1 1 0 1
10 
0 0 0 1 0 1 0 1 1 0
*/  