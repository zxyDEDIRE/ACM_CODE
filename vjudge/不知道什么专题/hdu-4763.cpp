#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int maxn=1e6+100;
// struct Seg{
// 	int l,r,val;
// }t[maxn*2];
int nxt[maxn];
char s[maxn];
string str;
int len;
int n;
// void build(int rt,int l,int r){
// 	t[rt]={l,r,0};
// 	if(l==r){
// 		t[rt].val=nxt[l];
// 		return ;
// 	}
// 	int mid=(l+r)>>1;
// 	build(rt<<1,l,mid);
// 	build(rt<<1|1,mid+1,r);
// 	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
// }
// int query(int rt,int l,int r){
// 	if(l<=t[rt].l&&t[rt].r<=r)
// 		return t[rt].val;
// 	int mid=(t[rt].l+t[rt].r)>>1;
// 	int ans=0;
// 	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
// 	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
// 	return ans;
// }
void init(char *s)
{
	nxt[1]=0;
	len=strlen(s+1);
	for(int i=2;i<=len;i++)
	{
		nxt[i]=nxt[i-1];
		while(s[nxt[i]+1]!=s[i]&&nxt[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])nxt[i]++;
	}
}
bool query(int l,int r,int k){
	for(int i=l;i<=r;i++)
		if(nxt[i]>=k)return 1;
	return 0;
}
void solve()
{
	cin>>str;
	n=str.size();
	for(int i=1;i<=n;i++)
		s[i]=str[i-1];
	s[n+1]='\0';
	init(s);
	// kmp.debug();
	int ma=nxt[n];
	// build(1,1,n);
	for(int i=ma;i>=0;i--)
	{
		int l=i+i;
		int r=n-i;
		// cout<<i<<" "<<l<<" "<<r<<endl;
		// if(l>r)continue;
		if(query(l,r,i)){
			cout<<i<<endl;
			return ;
		}
	}
	// cout<<0<<endl;

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
/*
aa aa ba
*/