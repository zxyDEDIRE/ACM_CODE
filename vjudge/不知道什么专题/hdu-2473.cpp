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
const int maxn=1e6+1e5+10;
int t[maxn];
int p[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
int fd(int r){
	return t[r]=t[r]==r?t[r]:fd(t[r]);
}
void solve()
{
	int step=1;
	while(cin>>n>>m&&n)
	{
		int k=n;
		for(int i=1;i<=n+m;i++)
			p[i]=t[i]=i;
		for(int i=1;i<=m;i++)
		{
			char ch;
			cin>>ch;
			if(ch=='M')
			{
				int x,y;
				cin>>x>>y;
				x++,y++;
				x=fd(x);
				y=fd(y);
				int fa=find(x);
				int fb=find(y);
				if(fa!=fb)
					p[fa]=fb;
			}
			else if(ch=='S')
			{
				int x;
				cin>>x;
				x++;
				x=fd(x);
				t[x]=++k;
			}
		}
		int cnt=0;
		set<int>s;
		for(int i=1;i<=n;i++)
		{
			s.insert(find(fd(i)));
		}
		cout<<"Case #"<<step<<": "<<s.size()<<endl;
		step++;
	}

}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}
/*
*/