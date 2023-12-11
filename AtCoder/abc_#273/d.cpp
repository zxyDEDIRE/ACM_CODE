/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
map<int,int>X,Y;
vector<vector<int>>vx;
vector<vector<int>>vy;
int num_x,num_y;
int n,m,s,t,aa;
void solve()
{
// 	cin>>n>>m>>s>>t;
// 	cin>>aa;
	scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
	scanf("%lld",&aa);
	for(int i=1;i<=aa;i++)
	{
		int x,y;
		// cin>>x>>y;
		scanf("%lld%lld",&x,&y);
		if(!X.count(x))
		{
			X[x]=num_x++;
			// vector<int>v;
			// vx.push_back(v);
			// vx[X[x]].push_back(y);
			vx.push_back({y});
		}
		else
		{
			vx[X[x]].push_back(y);
		}

		if(!Y.count(y))
		{
			Y[y]=num_y++;
			// vector<int>v;
			// vy.push_back(v);
			// vy[Y[y]].push_back(x);
			vy.push_back({x});
		}
		else 
			vy[Y[y]].push_back(x);
	}
	for(auto &i:vx)
		sort(i.begin(),i.end());
	for(auto &i:vy)
		sort(i.begin(),i.end());
	int q;
	cin>>q;

	while(q--)
	{
		char ch;int k;
		// cin>>ch>>k;
		scanf("%s %lld",&ch,&k);
		if(ch=='U')
		{
			if(!Y.count(t))
				s=max(1ll,s-k);
			else
			{
				vector<int>v=vy[Y[t]];
				int fl=lower_bound(v.begin(),v.end(),s)-v.begin();
				if(fl==0)s=max(1ll,s-k);
				else s=max(v[fl-1]+1,max(1ll,s-k));
			}
		}
		else if(ch=='D')
		{
			if(!Y.count(t))
				s=min(n,s+k);
			else
			{
				vector<int>v=vy[Y[t]];
				int fl=upper_bound(v.begin(),v.end(),s)-v.begin();
				if(fl==v.size())s=min(n,s+k);
				else s=min(min(n,s+k),v[fl]-1);
			}
		}
		else if(ch=='L')
		{
			if(!X.count(s))
				t=max(1ll,t-k);
			else
			{
				vector<int>v=vx[X[s]];
				int fl=upper_bound(v.begin(),v.end(),t)-v.begin();
				if(fl==0)t=max(1ll,t-k);
				else t=max(max(1ll,t-k),v[fl-1]+1);
			}
		}
		else if(ch=='R')
		{
			if(!X.count(s))
				t=min(m,t+k);
			else
			{
				vector<int>v=vx[X[s]];
				int fl=upper_bound(v.begin(),v.end(),t)-v.begin();
				if(fl==v.size())t=t=min(m,t+k);
				else t=min(min(m,t+k),v[fl]-1);
			}
		}
		cout<<s<<" "<<t<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}