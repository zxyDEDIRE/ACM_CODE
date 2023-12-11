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
const int maxn=1e6+100;
struct node{
	int x,y;
}a[maxn];
int p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y;
	sort(p+1,p+1+n,[&](int a,int b){
		return a>b;
	});
	sort(a+1,a+1+m,[&](node a,node b){
		return a.x>b.x;
	});
	priority_queue<int,vector<int>,greater<int>>q;
	int j=1,ans=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=p[i];
		while(j<=m&&a[j].x>p[i])
		{
			if(q.size())
			{
				int x=q.top();
				if(x<a[j].y)
				{
					q.pop();
					ans=ans-x+a[j].y;
					q.push({a[j].y});
				}
			}
			j++;
		}
		if(j<=m)
		{
			ans+=a[j].y;
			q.push(a[j].y);
			j++;
		}
	}
	// cout<<ans<<endl;
	for(;j<=m;j++)
	{
		if(q.size())
		{
			int x=q.top();
			if(x<a[j].y)
			{
				q.pop();
				ans=ans-a[j].y+x;
				q.push({a[j].x});
			}
		}
	}
	cout<<max(0ll,sum-ans)<<endl;
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