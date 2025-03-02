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
bitset<maxn>va,vb;
int a[maxn],b[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(!va[p[i]])va[p[i]]=1,a[i]=p[i];
		else if(!vb[p[i]])vb[p[i]]=1,b[i]=p[i];
		else {
			cout<<-1<<endl;
			return ;
		}
	}
	int fa=1;
	for(int i=1;i<=n;i++){
		if(a[i])continue;
		while(va[fa])fa++;
		a[i]=fa;fa++;
	}
	fa=1;
	for(int i=1;i<=n;i++){
		if(b[i])continue;
		while(vb[fa])fa++;
		b[i]=fa;fa++;
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}