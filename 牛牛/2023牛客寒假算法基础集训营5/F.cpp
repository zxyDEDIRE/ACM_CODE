/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int l,r;
	char val;
}t[maxn<<2];
char ans[maxn];
string s;
int n,k;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=ans[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
char query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	char ans='a';
	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}
void update(int rt,int l,char c)
{
	if(t[rt].l==t[rt].r){
		t[rt].val=c;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,c);
	else update(rt<<1|1,l,c);
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
void solve()
{
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)
		ans[i+1]=s[i];
	build(1,1,n);
	priority_queue<char>sa;
	for(int i=1;i<=n;i++)
	{
		if(k==0)break;
		char x=query(1,i+1,n);
		if(x<=ans[i])continue;
		else
		{
			sa.push(ans[i]);
			ans[i]=(char)('a'-1);
			k--;
		}
	}
	for(int i=1;i<=n;i++)
		if(ans[i]>='a'&&ans[i]<='z')
			cout<<ans[i];
	while(sa.size())
		cout<<sa.top(),sa.pop();
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
ebcdd
eddcb
*/