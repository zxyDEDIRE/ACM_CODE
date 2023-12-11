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
	int x,y,fl;
}p[maxn];
int a[maxn];
int T[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x;
		p[i].y=i;
		T[i]=i-1;
		p[i].fl=0;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.x!=b.x)return a.x<b.x;
		return a.y>b.y;
	});
	int r=0;
	int sum=0;
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		if(sum+p[i].x<=m)
		{
			sum+=p[i].x;
			r++;
			ma=max(ma,p[i].y);
			p[i].fl=1;
		}
		else
		{
			T[p[i].y]++;
		}
	}
	T[n+1]=r;
	int yu=p[r].y;
	int now=m-sum+p[r].x;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.y<b.y;
	});
	if(r+1<=n&&p[r+1].x<=now&&p[r+1].fl==0)
	{
		T[yu]++;
		T[r+1]--;
	}
	sort(T+1,T+2+n,[&](int a,int b){
		return a>b;
	});
	cout<<lower_bound(T+1,T+2+n,r,greater<int>() )-T<<endl;

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
/*
i=2
1:1
2:1
3:3
you:1


i=1
1:0
2:2
3:3
you:1
*/