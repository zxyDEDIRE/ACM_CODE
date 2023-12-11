/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
bool vis[maxn];
int s[maxn];
int p[maxn];
int t[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		vis[i]=0;
	for(int i=1;i<n;i++)
	{
		int x;cin>>x;
		s[i]=x;
		vis[x]=1;
		p[x]=i;
	}
	int fl;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			fl=i;
	int l=0,r=n;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
			cin>>t[j];
		int flag=0;
		for(int j=1;j<n;j++)
		{
			if(t[j]==fl)flag=1;
			else if(flag==0)
				l=max(l,p[t[j]]);
			else if(flag==1)
				r=min(r,p[t[j]]);
		}
	}
	int op=0;
	if(l==0)op=1;
	else if(r==n)op=n;
	else op=r;

	for(int i=1;i<op;i++)
		cout<<s[i]<<" ";
	cout<<fl<<" ";
	for(int i=op;i<n;i++)
		cout<<s[i]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
5
1 2 4 5
1 2 3 4
1 2 3 5
2 3 4 5
1 3 4 5
*/