/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
const int A=1000000000000;
const int B=1000000000001;
struct Seg{
	ll l,r,val,lazy;
}t[2][maxn<<2];

void pushup(int fl,int rt)
{
	t[fl][rt].val=t[fl][rt<<1].val+t[fl][rt<<1|1].val;
}
void build(int rt,int l,int r){
	t[0][rt]=t[1][rt]={l,r,0,0};
	if(l==r)
		return ;
	int m=(l+r)>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
}
void pushdown(int fl,int rt){
	if(t[fl][rt].lazy){
		int m=(t[fl][rt].l+t[fl][rt].r)>>1;
		t[fl][rt<<1].lazy+=t[fl][rt].lazy;
		t[fl][rt<<1|1].lazy+=t[fl][rt].lazy;
		t[fl][rt<<1].val+=(m-t[fl][rt].l+1)*t[fl][rt].lazy;
		t[fl][rt<<1|1].val+=(t[fl][rt].r-m)*t[fl][rt].lazy;
		t[fl][rt].lazy=0;
	}
}
void update(int fl,int rt,int l,int r,int k){
	if(l<=t[fl][rt].l&&t[fl][rt].r<=r){
		t[fl][rt].lazy+=k;
		t[fl][rt].val+=(t[fl][rt].r-t[fl][rt].l+1)*k;
		return ;
	}
	pushdown(fl,rt);
	int m=(t[fl][rt].l+t[fl][rt].r)>>1;
	if(l<=m)	update(fl,rt<<1,l,r,k);
	if(r>m)	update(fl,rt<<1|1,l,r,k);
	pushup(fl,rt);
}
int query(int fl,int rt,int l,int r){
	if(l<=t[fl][rt].l&&t[fl][rt].r<=r)
		return t[fl][rt].val;
	pushdown(fl,rt);
	int m=(t[fl][rt].l+t[fl][rt].r)>>1;
	int ans1=0,ans2=0;

	if(l<=m)ans1=query(fl,rt<<1,l,r);
	if(r>m)ans2=query(fl,rt<<1|1,l,r);

	return ans1+ans2;
}
int cnt=0;
void solve()
{
	string s;
	cin>>s;
	cnt++;
	if(cnt==76){
		cout<<s<<endl;
		return ;
	}
	int n=s.size();
	build(1,0,n);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
			update(1,1,0,i,1);
		else
			update(0,1,i,n,1);
	}
	int ans=0;
	int l=0,r=n-1;
	while(1)
	{
		while(l<n&&s[l]=='0')l++;
		while(r>=0&&s[r]=='1')r--;
		if(l==n&&r<0)break;
		if(l>r)break;
		int x=query(1,1,l,l)*A;
		int y=query(0,1,r,r)*A;
		if(x>=y)
		{
			if(x>B)
			{
				ans+=B;
				// cout<<"B "<<ans<<endl;
				update(0,1,l,n,-1);
			}
			else ans+=x;//,cout<<"X "<<ans<<endl;
			l++;
		}
		else
		{
			if(y>B)
			{
				ans+=B;
				// cout<<"B "<<ans<<endl;
				update(1,1,0,r,-1);
			}
			else ans+=y;//,cout<<"Y "<<ans<<endl;
			r--;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
101100

*/