/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
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
	int l,r,w;
	bool operator<(const node&a)const{
		return a.r<r;
	}
}p[maxn],now;
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i].l>>p[i].r>>p[i].w;
	int ma=-1,ans=0;
	set<node>s;
	s.insert(p[1]);
	ans=p[1].w;
	if(s.size()>=k)ma=max(ma,ans);
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.l!=b.l)return a.l<b.l;
		return a.r<b.r;
	});
	for(int i=2;i<=n;i++)
	{
		while(s.size())
		{
			now=*s.begin();
			if(now.r>=p[i].l)break;
			ans^=now.w;
			s.erase(now);
			if(s.size()>=k)ma=max(ma,ans);
		}
		s.insert(p[i]);
		ans^=p[i].w;
		if(s.size()>=k)ma=max(ma,ans);
	}
	cout<<ma<<endl;
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