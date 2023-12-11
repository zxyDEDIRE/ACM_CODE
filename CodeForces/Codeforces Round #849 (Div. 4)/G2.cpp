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
struct node{
	int x,y;
}p[maxn];
int sum[maxn];
int n,c;
void solve()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		p[i].x=min(x+i,x+n-i+1);
		p[i].y=x+i;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.x==b.x)return a.y<b.y;
		return a.x<b.x;
	});
	int ans=0;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+p[i].x;
	auto check=[&](int mid,int i)->bool{
		int val=sum[mid];
		if(mid>=i)val-=p[i].x;
		if(val+p[i].y<=c)return 1;
		else return 0;
	};
	for(int i=1;i<=n;i++)
	{
		if(p[i].y>c)continue;
		int l=0,r=n,now=l;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(check(mid,i))l=mid,now=mid;
			else r=mid;
		}
		while(now+1<=n&&check(now+1,i))now++;
		ans=max(ans,now+(now<i));
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}