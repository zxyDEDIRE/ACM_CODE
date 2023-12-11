#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
int p[maxn];
string str;
int n;
struct Seg{
	int l,r,val;
}t[maxn<<2];
void pushup(int rt)
{
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)
	{
		t[rt].val=p[l];
		return ;
	}
	int m=(l+r)>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int m=(t[rt].l+t[rt].r)>>1;
	int ans1=0,ans2=0;
	if(l<=m)ans1=query(rt<<1,l,r);
	if(r>m)ans2=query(rt<<1|1,l,r);
	return max(ans1,ans2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>str;
	for(int i=0;i<n;i++){
		if(str[i]=='1'){
			int v=1;
			for(int j=i;j<n&&j<(i+10);j++){
				
				if(str[j]=='1')v++;
				else v--;
				if(v==0)break;
				if(v==1)p[i+1]=j-i+1;
			}
		}
	}

	build(1,1,n);
	int m;
	cin>>m;
	while(m--)
	{
		int l,r,ans=0;
		cin>>l>>r;
		if(r-l>=10)ans=query(1,l,r-10);
		for(int i=max(l-1,r-10);i<r;i++)
		{
		//	cout<<i<<endl;
			if(str[i]=='1')
			{
				int v=1;
				for(int j=i;j<r&&j<(i+10);j++){
					if(str[j]=='1')v++;
					else v--;
					if(v==0)break;
					if(v==1)ans=max(ans,j-i+1);
				}
			}
		}
	//	cout<<"ans:";
		cout<<ans<<"\n";
	}
}
/*
0123456789
1 11

6
110010
4
1 6
1 3
3 5
2 4
*/
