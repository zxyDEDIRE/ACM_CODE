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
int a[maxn];
int nxt[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],nxt[i]=-1,a[i]=-1;
	stack<int>s[100];
	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		if(x==0)s[0].push(i);
		else
		{
			int y=s[x-1].top();
			s[x-1].pop();
			nxt[y]=i;
			s[x].push(i);
		}
	}
	int now=0;
	for(int i=1;i<=n;i++)
	{
		if(nxt[i]!=-1)
			a[nxt[i]]=a[i];
		if(a[i]!=-1)continue;
		if(p[i]==0)a[i]=now++;
		if(nxt[i]!=-1)
			a[nxt[i]]=a[i];
	}
	for(int i=1;i<=n;i++)
		cout<<(char)(a[i]+'a');
	cout<<endl;


}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}