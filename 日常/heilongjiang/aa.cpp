#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	int l,r,val;
}t[maxn<<2];
vector<int>v;
string str;
int n,q;
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		if(str[l]=='0'&&str[l-1]!='1')t[rt].val=1;
		else t[rt].val=0;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int an=0;
	if(l<=mid)an+=query(rt<<1,l,r);
	if(r>mid)an+=query(rt<<1|1,l,r);
	return an;
}
void solve()
{
	cin>>n>>q>>str;
	str=" "+str;
	build(1,1,n);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=query(1,x+1,y);
		cout<<"ANS: "<<ans<<" ";
		if(str[x]=='0')ans++;
		if(str[y]=='0')ans++;
		cout<<ans<<endl;
		v.push_back(ans);
	}
	int ans=v[0];
	for(int i=1;i<v.size();i++)
		ans=(ans^v[i]);
	cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
//    cin>>__;
    __=1;
    while(__--)solve();
    return 0;
}
/*
1111001111
0001001111
*/