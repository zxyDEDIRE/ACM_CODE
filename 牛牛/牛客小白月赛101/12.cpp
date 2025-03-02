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
// /const int maxn=1e6+100;

const int maxn=2e5;
class Solution {
public:
	struct Seg{
		int l,r,val;
	}t[maxn];
	void build(int rt,int l,int r)
	{
		t[rt]={l,r,INF};
		if(l==r)return ;
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
	}
	void pushdown(int rt)
	{
		t[rt<<1].val=min(t[rt<<1].val,t[rt].val);
		t[rt<<1|1].val=min(t[rt<<1|1].val,t[rt].val);
	}
	void update(int rt,int l,int r,int val)
	{
		if(l<=t[rt].l&&t[rt].r<=r)
		{
			t[rt].val=min(t[rt].val,val);
			return ;
		}
		pushdown(rt);
		int mid=(t[rt].l+t[rt].r)>>1;
		if(l<=mid)update(rt<<1,l,r,val);
		if(r>mid)update(rt<<1|1,l,r,val);
	}
	int query(int rt,int l)
	{
		if(t[rt].l==t[rt].r)
			return t[rt].val;
		pushdown(rt);
		int mid=(t[rt].l+t[rt].r)>>1;
		if(l<=mid)return query(rt<<1,l);
		else return query(rt<<1|1,l);
	}
    int minValidStrings(vector<string>& w, string t) {
        int n=t.size();
        vector<int>dp(n+2,1e9);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            for(auto &s:w)
            {
                int y=0;
                int x=i;
                while(s[y]==t[x]&&y<(int)s.size()&&x<n){
                    dp[x+1]=min(dp[x+1],dp[i]+1);
                    x++,y++;
                }
            }
        }
        if(dp[n]==1e9)dp[n]=-1;
        return dp[n];
    }
};



signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		// solve();

	vector<int>p={1,3,6,10};
	int fl=lower_bound(p.begin(),p.end(),2)-p.begin();
	cout<<fl<<endl;
	return 0;
}