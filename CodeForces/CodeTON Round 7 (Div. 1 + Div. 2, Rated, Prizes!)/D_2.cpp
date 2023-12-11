#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n,q;
void solve()
{
	cin>>n>>q;
	int sum=0;
	set<int>s;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		sum+=p[i];
		if(p[i]==1)
		s.insert(i);
	}
	while(q--)
	{
		int op,x,w;
		cin>>op;
		if(op==1)
		{
			cin>>w;
			int flag=1;
			if(w>sum)flag=0;
			if(w%2==1&&s.size()==0)flag=0;
			if(s.size())
			{
				int l=*s.begin();
				int r=*s.rbegin();
				int sum_l=sum-(l-1)*2;
				int sum_r=sum-(n-r)*2;
				int ma=max(sum_l,sum_r);
				if((ma%2)!=(w%2) && w>ma)flag=0;
			}

			if(flag)cout<<"YES\n";
			else cout<<"NO\n";
		}
		else if(op==2)
		{
			cin>>x>>w;

			sum-=p[x];
			if(p[x]==1)s.erase(s.find(x));

			p[x]=w;

			sum+=p[x];
			if(p[x]==1)s.insert(x);
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
8 3
2 2 2 1 2 2 2 2
1 10
1 12
1 14
NO
NO
NO



10 4
2 2 2 2 1 1 2 2 2 2
1 11
1 13
1 15
1 1
NO
NO
NO
YES


13 1
2 2 1 2 2 1 1 2 1 2 2 2 2
1 19
NO

5 1
2 1 2 2 2
1 7
YES

13 3
2 2 2 1 1 2 1 2 1 1 2 2 2
1 16
1 18
1 20
NO
NO
NO

2 2 2 1 2 2 2 1 2 2 2 



001101010

*/