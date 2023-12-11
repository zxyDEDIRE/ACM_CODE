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
pii yu[111];
vector<int>v[11111][111];
map<double,int>mp;
int p[11111][111];
int num[11111][111];
int n,cnt;
void init(int x)
{
	for(int i=1;i<=n;i++)
		p[x][i]=i,num[x][i]=1;
}
int find(int x,int r)
{
	return p[x][r]=p[x][r]==r?p[x][r]:find(x,p[x][r]);
}
int c(int x,int y)
{
	int a=1,b=1;
	for(int i=1;i<=y;i++)
	{
		a*=x;x--;
		b*=i;
		int g=__gcd(a,b);
		a/=g;
		b/=g;
	}
	return a;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>yu[i].first>>yu[i].second;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double k;
			if(yu[i].first==yu[j].first)k=INF;
			else k=(1.0*(yu[i].second-yu[j].second)/(yu[i].first-yu[j].first));
			// cout<<i<<" "<<j<<" "<<k<<endl;
			if(!mp[k])
			{
				mp[k]=++cnt,init(cnt);
			}
			int now=mp[k];
			
			int fa=find(now,i);
			int fb=find(now,j);
			if(fa!=fb)
			{
				p[now][fa]=fb;
				num[now][fb]+=num[now][fa];
			}
		}
	}
	int ans=c(n,4);
	// cout<<endl;
	// cout<<ans<<endl;
	// cout<<cnt<<endl;cout<<endl;
	for(int now=1;now<=cnt;now++)
	{
		for(int i=1;i<=n;i++)
		{
			if(p[now][i]==i&&num[now][i]>=3)
			{
				// int x=num[now][i];
				// int y=c(x-1,3);
				// ans=ans-c(x,3)*(n-3)+y;
				// cout<<c(x,3)<<" "<<y<<endl;
				// //cout<<num[now][i]<<endl;
			}
		}
	}
	cout<<ans<<endl;
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
/*
9
-2 0
-1 0
1 0
2 0
0 1
0 2
0 -1
0 -2
0 0
*/