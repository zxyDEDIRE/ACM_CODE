/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int x,y,w;
}a[maxn];
int p[maxn];
int n,m;
void init(){
	for(int i=1;i<=n;i++)
		p[i]=i;
}
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	while(cin>>n>>m)
	{
		//cin>>n>>m;
		for(int i=1;i<=m;i++)
			cin>>a[i].x>>a[i].y>>a[i].w;
		sort(a+1,a+1+m,[&](node a,node b){
			return a.w<b.w;
		});
		int q;
		cin>>q;
		while(q--)
		{
			int s,t;
			cin>>s>>t;
			int mi=1e9;
			for(int i=1;i<=m;i++)
			{
				init();
				for(int j=i;j<=m;j++)
				{
					int flag=0;
					int fa=find(a[j].x);
					int fb=find(a[j].y);
					if(fa!=fb)
					{
						p[fa]=fb;
						int xx=find(s);
						int yy=find(t);
						if(xx==yy)
						{
							flag=1;
							mi=min(mi,a[j].w-a[i].w);
						}
					}
					if(flag)break;
				}
			}
			if(mi==1e9)cout<<-1<<endl;
			else cout<<mi<<endl;
		}
	}
	
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}