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
#define double long double
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,y,h,id;
}p[maxn];
bitset<maxn>vis;
int n,tot;
void solve()
{
	cin>>n;
	for(int op=1;op<=n;op++)
	{
		int fl,x,y,h,atk;
		double r;
		cin>>fl;
		if(fl==1)
		{
			cin>>x>>y>>h;
			p[++tot]={x,y,h,op};
		}
		else if(fl==2)
		{
			cin>>x>>y>>atk>>r;
			atk*=3;

			int mi=1e18;
			node now;
			for(int i=1;i<=tot;i++)
			{
				if(vis[p[i].id])continue;
				int dis=(p[i].x-x)*(p[i].x-x)+(p[i].y-y)*(p[i].y-y);
				if(mi==-1||dis<mi)
				{
					mi=dis;
					now=p[i];
				}
			}
			for(int i=1;i<=tot;i++)
			{
				if(vis[p[i].id])continue;
				int dis=(now.x-p[i].x)*(now.x-p[i].x)+(now.y-p[i].y)*(now.y-p[i].y);
				if(dis<=r*r)
				{
					if(p[i].h<=atk)vis[p[i].id]=1;
					else p[i].h-=atk,vis[op]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(vis[i])cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
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