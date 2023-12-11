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
					res.mp[i][j]=(res.mp[i][j]+mp[i][k]*b.mp[k][j]%mod)%mod;
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
int dfs(int x)
{
	id[x]=++tp;
	od[tp]=x;
	if(id[p[x]]) return t[x]=id[x];
	s[p[x]]=s[x];
	return t[x]=dfs(p[x]);
}
bool vis[N];
int dfs1(int x)
{
	vis[x]=true;
	id[x]=++tp;
	od[tp]=x;
	in[p[x]]--;
	if(in[p[x]]) return t[x]=id[x];
	s[p[x]]=s[x];
	return t[x]=dfs1(p[x]);
}
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
void solve()
{
	// cin>>n>>q;
	n=1e5;
	q=1e5;
	tp=0;
	for(int i=1;i<=n;i++)
	{
		vis[i]=false;
		in[i]=0;id[i]=0;
		// cin>>k[i];
		k[i]=rand()%n+1;
	}
	for(int i=1;i<=n;i++)
	{
		// cin>>b[i];
		b[i]=rand()%n+1;
	}
	for(int i=1;i<=n;i++)
	{
		// cin>>p[i];
		p[i]=rand()%n+1;
		in[p[i]]++;
	}
	vector<int>qq;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			qq.push_back(i);
		}
	}
	for(int v:qq){
		s[v]=tp+1;
		dfs1(v);
	}
	for(int i=1;i<=n;i++)
	{
		if(id[i]==0){
			s[i]=tp+1;
			dfs(i);
		}
	}

	build(1,1,n);
	while(q--)
	{
		int x,l,y;
		// cin>>x>>l>>y;
		x=rand()%n+1;
		y=rand()%n+1;
		l=rand()+1;
		mat a(1);
		int f=1;
		// while(vis[x]&&l)
		// {
		// 	if(f)
		// 	{
		// 		int le=t[x]-id[x];
		// 		le=min(l,le);
		// 		if(id[x]+1<=id[x]+le)
		// 		a=a*qr(1,1,n,id[x]+1,id[x]+le);
		// 		l-=le;
		// 		x=p[t[x]];
		// 	}
		// 	else{
		// 		int le=t[x]-id[x]+1;
		// 		le=min(l,le);
		// 		a=a*qr(1,1,n,id[x],id[x]+le-1);
		// 		l-=le;
		// 		x=p[t[x]];
		// 	}
		// 	f=0;
		// }
		int le=t[x]-s[x]+1;
		mat res(0);
		res.mp[0][0]=y;
		res.mp[0][1]=1;
		if(f)
		{
			if(l>=le)
			{
				if(id[x]==t[x]){
					a=a*qr(1,1,n,s[x],t[x]);
				}
				else{
					a=a*qr(1,1,n,id[x]+1,t[x])*qr(1,1,n,s[x],id[x]);
				}
				a=ksm(a,l/le);
				l%=le;
			}
			if(l)
			{
				if(id[x]==t[x])
				{
					a=a*qr(1,1,n,s[x],s[x]+l-1);
					l=0;
				}
				else{
					a=a*qr(1,1,n,id[x]+1,min(t[x],id[x]+l));
					l-=min(t[x]-id[x],l);
				}
				if(l)
				{
					a=a*qr(1,1,n,s[x],s[x]+l-1);
				}
			}
		}else{
			if(l>=le)
			{
				if(id[x]==s[x]){
					a=a*qr(1,1,n,s[x],t[x]);
				}
				else{
					a=a*qr(1,1,n,id[x],t[x])*qr(1,1,n,s[x],id[x]-1);
				}
				a=ksm(a,l/le);
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
		}
		res=res*a;
		// cout<<res.mp[0][0]<<'\n';
	}
}

int main()
{
	// ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=5;
	// cin>>t;
	clock_t start, finish;
	start = clock();
	while(t--)
	{
		solve();
		finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC<<endl;
	}
	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
	return 0;
}