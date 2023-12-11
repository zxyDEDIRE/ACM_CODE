#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4;
const int mod=1e9+7; 
struct node{
	int val,l,r;
}t[maxn];
int siz[maxn],ans[maxn];
int f[maxn],inf[maxn];
int p[maxn];
int tot,n;
int ksm(long long a,long long b)
{
	a%=mod;
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void init()
{
	for(int i=1;i<=n;i++){
		t[i].l=t[i].r=0;
		ans[i]=siz[i]=0;
	}
	tot=1;
}
void build(int rt,int k)
{
	int val=t[rt].val;
	if(k<val)
	{
		if(t[rt].l)build(t[rt].l,k);
		else
		{
			t[++tot].val=k;
			t[rt].l=tot;
			return ;
		}
	}
	else
	{
		if(t[rt].r)build(t[rt].r,k);
		else
		{
			t[++tot].val=k;
			t[rt].r=tot;
			return ;
		}
	}
}
int A(int x,int y){
	int now=((f[x+y]*inf[x])%mod*inf[y])%mod;
	return now;
}
void dfs(int rt)
{
	int ans_1=1,ans_2=1;
	int s_1=0,s_2=0;
	siz[rt]=1;
	ans[rt]=1;
	if(t[rt].l)
	{
		dfs(t[rt].l);
		ans_1=ans[t[rt].l];
		s_1=siz[t[rt].l];
	}
	if(t[rt].r)
	{
		dfs(t[rt].r);
		ans_2=ans[t[rt].r];
		s_2=siz[t[rt].r];
	}
	siz[rt]+=s_1+s_2;
	ans[rt]=((ans_1*ans_2)%mod*A(s_1,s_2))%mod;
}
void solve()
{
//	cin>>n;
	init(); 
	for(int i=1;i<=n;i++)
		cin>>p[i];
	t[1].val=p[1];
	for(int i=2;i<=n;i++){
		build(1,p[i]);
	}
	dfs(1);
	cout<<ans[1]<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	f[0]=inf[0]=1;
	for(int i=1;i<=1e3;i++)
	{
		f[i]=(f[i-1]*i)%mod;
		inf[i]=ksm(f[i],mod-2);
	}
	while(cin>>n)
		solve();
} 
