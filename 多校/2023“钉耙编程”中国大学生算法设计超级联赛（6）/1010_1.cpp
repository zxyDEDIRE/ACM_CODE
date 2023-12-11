#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=1e9+7;
struct mat
{
	long long mp[2][2];
	mat()
	{
		mp[0][0]=0;mp[0][1]=0;
		mp[1][0]=0;mp[1][1]=0;
	}
	mat(int x)
	{
		mp[0][0]=x;mp[0][1]=0;
		mp[1][0]=0;mp[1][1]=x;
	}
	void init(int k,long long b)
	{
		mp[0][0]=k;mp[0][1]=0;
		mp[1][0]=b;mp[1][1]=1;
	}
	mat operator *(mat b)
	{
		mat res;
		for(int k=0;k<2;k++)
		{
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<2;j++)
				{
					res.mp[i][j]=(res.mp[i][j]+mp[i][k]%mod*b.mp[k][j]%mod)%mod;
				}
			}
		}
		return res;
	}
};
int n,q;
int k[N],b[N],p[N];
int in[N],id[N];
int od[N];
int tp;
int s[N],t[N];
mat tr[N<<2];
mat tr1[N<<2];
void build(int kp,long long l,long long r)
{
	if(l==r)
	{
		tr[kp].init(k[od[l]],b[od[l]]);
		return;
	}
	int mi=(l+r)>>1;
	build(kp<<1,l,mi);
	build(kp<<1|1,mi+1,r);
	tr[kp]=tr[kp<<1]*tr[kp<<1|1];
}
void build1(int kp,long long l,long long r)
{
	if(l==r)
	{
		tr1[kp].init(k[od[l]],b[od[l]]);
		return;
	}
	int mi=(l+r)>>1;
	build1(kp<<1,l,mi);
	build1(kp<<1|1,mi+1,r);
	tr1[kp]=tr1[kp<<1|1]*tr1[kp<<1];
}
mat qr(int kp,int l,int r,int x,int y)
{
	if(x>y)
	{
		mat re(1);
		return re;
	}
	if(l==x&&r==y)
	{
		return tr[kp];
	}
	int mi=(l+r)>>1;
	if(y<=mi) return qr(kp<<1,l,mi,x,y);
	else if(mi<x) return qr(kp<<1|1,mi+1,r,x,y);
	else return (qr(kp<<1,l,mi,x,mi)*qr(kp<<1|1,mi+1,r,mi+1,y));
}
mat qr1(int kp,int l,int r,int x,int y)
{
	if(x>y)
	{
		mat re(1);
		return re;
	}
	if(l==x&&r==y)
	{
		return tr1[kp];
	}
	int mi=(l+r)>>1;
	if(y<=mi) return qr1(kp<<1,l,mi,x,y);
	else if(mi<x) return qr1(kp<<1|1,mi+1,r,x,y);
	else return (qr1(kp<<1|1,mi+1,r,mi+1,y)*qr1(kp<<1,l,mi,x,mi));
}
bool vis[N];
mat ksm(mat a,int b)
{
	mat res(1);
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
/*
1
5 5
2 3 1 2 4
3 4 2 1 2
3 3 4 5 4
1 2 4
2 4 5
3 3 4
4 5 2
5 2 1
*/
int siz[N], son[N], dep[N], dfn[N], fat[N], top[N];
int cnt;
int dfs1(int x)
{
	id[x]=++cnt;
	od[cnt]=x;
	if(id[p[x]]) return t[x]=id[x];
	s[p[x]]=s[x];
	return t[x]=dfs1(p[x]);
}
vector<int> g[N];
void dfs(int u, int fa){
    fat[u] = fa;
    dep[u] = dep[fa] + 1;
    siz[u] = 1;
    son[u] = 0;
    for(auto v : g[u]){
        dfs(v, u);
        siz[u] += siz[v];
        if(siz[v] > siz[son[u]]) son[u] = v; 
    }  
}

void dfs2(int u, int topx){
    top[u] = topx;
    dfn[u] = ++ cnt;
    od[cnt] = u;
    if(son[u] != 0) dfs2(son[u], topx);
    for(auto v : g[u]){
        if(v != son[u]) dfs2(v, v);
    }
}

void solve()
{
	cin>>n>>q;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		vis[i]=false;
		g[i].clear();
		in[i]=0;id[i]=0;
		cin>>k[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		g[p[i]].push_back(i);
		in[p[i]]++;
	}
	queue<int>qp;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			qp.push(i);
		}
	}
	while(qp.size()){
		int u=qp.front();
		qp.pop();
		vis[u]=true;
		if(--in[p[u]]==0) qp.push(p[u]);
	}
	for(int i=1;i<=n;i++){
		if(vis[p[i]]==false&&vis[i]==true){
			qp.push(i);
		}
	}
	while(qp.size())
	{
		int u=qp.front();
		qp.pop();
		dfs(u,0);
		dfs2(u,u);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==false&&id[i]==0){
			
			s[i]=cnt+1;
			dfs1(i);
		}
	}
	build(1,1,n);
	build1(1,1,n);
	while(q--)
	{
		int x,l,y;
		cin>>x>>l>>y;
		mat a(1);
		int f=1;
		x=p[x];
		while(vis[x]&&l)
		{
			int le=dfn[x]-dfn[top[x]]+1;
			le=min(l,le);
			a=a*qr1(1,1,n,dfn[x]-le+1,dfn[x]);
			l-=le;
			x=p[top[x]];
		}
		int le=t[x]-s[x]+1;
		mat res(0);
		res.mp[0][0]=y;
		res.mp[0][1]=1;
		if(l>=le)
		{
			mat o;
			if(id[x]==s[x]){
				o=qr(1,1,n,s[x],t[x]);
			}
			else{
				o=qr(1,1,n,id[x],t[x])*qr(1,1,n,s[x],id[x]-1);
			}
			a=a*ksm(o,l/le);
			l%=le;
		}
		if(l)
		{
			if(id[x]==s[x])
			{
				a=a*qr(1,1,n,s[x],s[x]+l-1);
				l=0;
			}
			else{
				a=a*qr(1,1,n,id[x],min(t[x],id[x]+l-1));
				l-=min(t[x]-id[x]+1,l);
			}
			if(l)
			{
				a=a*qr(1,1,n,s[x],s[x]+l-1);
			}
		}
		res=res*a;
		cout<<res.mp[0][0]<<'\n';
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
