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
int p[maxn];
int f[maxn];
int l[maxn];
int r[maxn];
int n,q;
int find(int x){
	if(f[x]==x)return x;
	int fa=find(f[x]);
	l[fa]=min(l[fa],l[x]);
	r[fa]=max(r[fa],r[x]);
	return f[x]=fa;
}
int merge(int x,int y)
{
	if(p[x]>p[y]){
		f[y]=x;
		return x;
	}
	else   {
		f[x]=y;
		return y;
	}
}
void F(int _l,int _r)
{
	int rt=find(_l);
	while(r)
	{
		int R=r[rt];
		if(R>=_r)break;
		int fb=find(R+1);
		rt=merge(rt,fb);
	}
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		f[i]=l[i]=r[i]=i;
	}
	while(q--)
	{
		int op,_l,_r,x;
		cin>>op;
		if(op==1)
		{
			cin>>_l>>_r;
			F(_l,_r);
		}
		else
		{
			cin>>x;
			int fa=find(x);
			cout<<p[find(x)]<<endl;
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
5 5
1 2 3 4 5
1 1 2
1 2 3
1 3 4
1 4 5
2 1
*/
