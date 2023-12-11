#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
struct node{
	int l,r,val,ma=0,mi=0x3f3f3f3f,cnt=0;
}t[maxn];
int p[maxn];
int n;
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}
inline void write(int x){
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+'0');
} 
void pushup(int rt)
{
	t[rt].mi=min(t[rt<<1].mi,t[rt<<1|1].mi);
	t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
	t[rt].cnt=t[rt<<1].cnt+t[rt<<1|1].cnt;
}
void build(int rt,int l,int r){
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		t[rt].val=t[rt].ma=t[rt].mi=p[l];
		t[rt].cnt=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
int query(int rt,int l,int r,int k)
{
	if(t[rt].mi>=k)return 0;
	if(l<=t[rt].l&&t[rt].r<=r&&t[rt].ma<k){
		return t[rt].cnt;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans1=0,ans2=0;
	if(l<=mid)ans1=query(rt<<1,l,r,k);
	if(r>mid)ans2=query(rt<<1|1,l,r,k);
	return ans1+ans2;
}
void solve()
{
	read(n);
	for(int i=1;i<=n;i++)
		read(p[i]);
	build(1,1,n);
	int ans=0;
	for(int i=2;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			int ans1=query(1,1,i-1,p[j]);
			int ans2=query(1,j+1,n,p[i]);
			ans+=ans1*ans2;
		}
	}
	write(ans);
	puts("");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int __;cin>>__;
	while(__--)solve();
}