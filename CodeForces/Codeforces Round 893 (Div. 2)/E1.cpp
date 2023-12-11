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
struct node{
	int id;
	int &d;
	int num;
};
stack<node>s;
int p[maxn];
int vis[maxn];
int dis[maxn];
int q,tot,cnt;
void solve()
{
	cin>>q;
	for(int i=1;i<=1e6+10;i++)
		vis[i]=INF;
	while(q--)
	{
		char op;
		cin>>op;
		if(op=='+')
		{
			int x;cin>>x;
			cnt++;

			if(p[tot+1]!=0&&vis[p[tot+1]]==tot+1){
				s.push({cnt,vis[p[tot+1]],vis[p[tot+1]]});
				vis[p[tot+1]]=INF;
			}

			if(vis[x]>tot)
			{
				s.push({cnt,vis[x],vis[x]});
				s.push({cnt,dis[tot+1],dis[tot+1]});
				vis[x]=tot+1;
				dis[tot+1]=dis[tot]+1;
			}
			else
			{
				s.push({cnt,dis[tot+1],dis[tot+1]});
				dis[tot+1]=dis[tot];
			}
			s.push({cnt,tot,tot});
			s.push({cnt,p[tot+1],p[tot+1]});
			tot++;
			p[tot]=x;
		}
		else if(op=='-')
		{
			++cnt;
			int x;cin>>x;
			s.push({cnt,tot,tot});
			tot-=x;
		}
		else if(op=='!')
		{
			int id=s.top().id;
			while(s.size()&&s.top().id==id)
			{
				auto [id,d,num]=s.top();
				s.pop();
				d=num;
			}
		}
		else if(op=='?')
		{
			cout<<dis[tot]<<endl;
		}

		// cout<<"tot "<<tot<<endl;
		// for(int i=1;i<=tot;i++)
		// 	cout<<p[i]<<" \n"[i==tot];
		// for(int i=1;i<=tot;i++)
		// 	cout<<dis[i]<<" \n"[i==tot];
		// for(int i=1;i<=tot;i++)
		// 	cout<<vis[i]<<" \n"[i==tot];
		// cout<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
12
?
+ 1
?
+ 1
?
- 1
+ 2
?
- 2
+ 2
+ 1
?
*/