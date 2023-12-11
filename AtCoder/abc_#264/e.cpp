/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct node{
	int x,y;
}a[maxn];
bitset<maxn>vis;
bitset<maxn>ok;
int p[maxn];
int num[maxn];
int q[maxn];
int res[maxn];
int n,m,Q,E,s;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>m>>E;
	s=n+m+1;
	for(int i=1;i<=n;i++)
		p[i]=i,num[i]=1;
	num[n+m]=0;
	for(int i=1;i<=E;i++)
		cin>>a[i].x>>a[i].y;
	cin>>Q;
	for(int i=1;i<=Q;i++)
		cin>>q[i],vis[q[i]]=1;
	for(int i=n+1;i<=n+m;i++)
		p[i]=s;
	p[s]=s;
	ok[s]=1;
	int ans=0;
	for(int i=1;i<=E;i++)
	{
		if(!vis[i])
		{
			int x=a[i].x;
			int y=a[i].y;
			int fa=find(x);
			int fb=find(y);
			if(fa!=fb)
			{
				// cout<<s<<endl;
				// cout<<x<<" "<<y<<endl;
				// cout<<fa<<" "<<fb<<endl;
				// cout<<ok[fa]<<" "<<ok[fb]<<endl;
				if(ok[fa]&&!ok[fb])
				{
					p[fb]=fa;
					num[fa]+=num[fb];
					ans+=num[fb];
				}
				else if(ok[fb]&&!ok[fa])
				{
					p[fa]=fb;
					num[fb]+=num[fa];
					ans+=num[fa];
				}
				else if(ok[fa]&&ok[fb])
				{
					p[fa]=fb;
					num[fb]+=num[fa];
				}
				else
				{
					p[fa]=fb;
					num[fb]+=num[fa];
				}
			}				
		}
	}
	for(int i=Q;i>=1;i--)
	{
		res[i]=ans;

		int x=a[q[i]].x;
		int y=a[q[i]].y;
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
		{
			if(ok[fa])
			{
				p[fb]=fa;
				num[fa]+=num[fb];
				ans+=num[fb];
			}
			else if(ok[fb])
			{
				p[fa]=fb;
				num[fb]+=num[fa];
				ans+=num[fa];
			}
			else
			{
				p[fa]=fb;
				num[fb]+=num[fa];
			}
		}		
	}
	for(int i=1;i<=Q;i++)
		cout<<res[i]<<endl;

}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 3
1 3 1
3 1 4
1 5 6
2 2
3 4
5 6
*/