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
	bool operator<(const node&a)const{
		if(a.l!=l)return a.l>l;
		return a.r<r;
	}
};
set<node>sa;
set<node>sb;
node a[maxn];
node b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].l>>a[i].r;
	for(int i=1;i<=n;i++)
		cin>>b[i].l>>b[i].r;
	int x=1,y=1;
	for(int i=1;i<=n;i++)
	{
		sa.insert(a[i]);
		sb.insert(b[i]);
		while(sa.size())
		{
			auto [xx,yy]=*sa.begin();
			if(xx<=x)x=max(x,yy+1),sa.erase({xx,yy});
			else break;
		}
		while(sb.size())
		{
			auto [xx,yy]=*sb.begin();
			if(xx<=y)y=max(y,yy+1),sb.erase({xx,yy});
			else break;
		}
		if(x>y)
			cout<<"sa_win!"<<endl;
		else if(x<y)
			cout<<"ya_win!"<<endl;
		else cout<<"win_win!"<<endl;
		cout<<abs(x-y)<<endl;
	}
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
3
1 1
3 5
2 2

1 2
3 3
4 4
*/