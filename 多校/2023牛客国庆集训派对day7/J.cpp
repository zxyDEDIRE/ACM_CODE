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
const int maxn=1e3+100;
struct node{
	array<int,30>a;
	int x;
}p[maxn];
struct N{
	pii a,b;
}a[maxn];
int in[maxn];
set<int>ans[maxn];
vector<int>v[maxn];
bool mp[111][111];
int n,tot;
int f(char ch){
	if(ch>='a'&&ch<='z')return 26+ch-'a'+1;
	return ch-'A'+1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=26;i++)
		in[i]=++tot;
	for(int i=1;i<=26;i++)
	{
		p[i].x=++tot;
		for(int j=1;j<=26;j++)
			p[i].a[j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		string str;
		getline(cin,str);
		if(str[1]=='.')
		{
			a[i].a.first=f(str[0]);
			a[i].a.second=f(str[2]);

			if(str[7]=='.')
			{
				a[i].b.first=f(str[6]);
				a[i].b.second=f(str[8]);
			}
			else
			{
				a[i].b.first=f(str[6]);
				a[i].b.second=0;
			}
		}
		else
		{
			a[i].a.first=f(str[0]);
			a[i].a.second=0;
			if(str[5]=='.')
			{
				a[i].b.first=f(str[4]);
				a[i].b.second=f(str[6]);
			}
			else
			{
				a[i].b.first=f(str[4]);
				a[i].b.second=0;
			}
		}
	}
	while(1)
	{
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			auto [x,y]=a[i];
			
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
		solve();
	return 0;
}