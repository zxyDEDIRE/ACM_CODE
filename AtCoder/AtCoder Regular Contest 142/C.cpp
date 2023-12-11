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
pii p[maxn];
int n,m;
void solve()
{
	cin>>n;
	if(n==3){
		int x,y;
		cout<<"? 1 3"<<endl;
		cin>>x;
		cout<<"? 2 3"<<endl;
		cin>>y;
		cout<<"! ";
		if(x==1&&y==1)cout<<2<<endl;
		else cout<<1<<endl;
		return ;
	}
	for(int i=3;i<=n;i++)
	{
		cout<<"? 1 "<<i<<endl;
		cin>>p[i].first;
	}
	for(int i=3;i<=n;i++)
	{
		cout<<"? 2 "<<i<<endl;
		cin>>p[i].second;
	}
	int l=1,r=n-1;
	// cout<<endl;
	for(int i=3;i<=n;i++)
	{
		auto [x,y]=p[i];
		// cout<<abs(x-y)<<" "<<x+y<<endl;
		l=max(l,abs(x-y));
		r=min(r,x+y);
	}
	// cout<<l<<" "<<r<<endl;
	cout<<"! ";
	if(l==1&&r==n-1)
	{
		// int flag=1;
		// for(int i=4;i<=n;i++)
		// 	if(p[i].first+p[i].second==p[3].first+p[3].second)
		// 		flag=0;
		// if(flag){
		// 	cout<<1<<endl;
		// }
		// else cout<<n-1<<endl;
		cout<<n-1<<endl;
	}
	else cout<<l<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6

8
1
2
3
4
4
5
2
1
2
1
1
2
*/