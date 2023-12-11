/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int a[maxn];
struct node{
	int x,y;
}p[maxn];
map<int,int>mp;
set<int>s;
int n,tot,ans;
void solve()
{
	cin>>n;
	s.clear();
	mp.clear();
	tot=0;
	ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==p[tot].x)p[tot].y++;
		else p[++tot].x=a[i],p[tot].y=1,s.insert(a[i]);
	}
	for(int i=1;i<=tot;i++){
		if(p[i].y>=3)ans+=p[i].y*(p[i].y-1)*(p[i].y-2);
		mp[p[i].x]=p[i].y;
		// cout<<p[i].x<<" "<<p[i].y<<endl;
	}
	int mi=p[1].x;
	int ma=p[tot].x;
	for(int i=2;i<n;i++)
	{
		int x=p[i].x;
		for(int j=2;j;j++)
		{
			if(x/j<mi||x*j>ma)break;
			if(x%j!=0)continue;
			if(s.count(x/j)&&s.count(x*j))
			{
				ans+=mp[x/j]*mp[x*j]*p[i].y;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
A(4 3)
1 2 4
1 3 9
2 4 8
*/