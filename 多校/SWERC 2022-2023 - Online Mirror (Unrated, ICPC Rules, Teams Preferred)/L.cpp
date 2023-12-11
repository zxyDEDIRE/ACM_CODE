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
void solve()
{
	int n;
	string str;
	cin>>n;
	cin>>str;
	int cnt_a=0,cnt_b=0;
	for(auto i:str)
		if(i=='+')cnt_a++;
		else cnt_b++;
	if(cnt_a>cnt_b)swap(cnt_a,cnt_b);
	
	
	auto check=[&](int mid,int x,int y)->int{
		// cout<<(cnt_a-mid)*x+mid*y<<" "<<cnt_b*x<<endl;
		return (cnt_a-mid)*x+mid*y-cnt_b*x;
	};

	// cout<<cnt_a<<" "<<cnt_b<<endl;

	cin>>n;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		int l=0,r=cnt_a;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			int ans=check(mid,x,y);
			if(ans<=0)l=mid;
			else r=mid;
		}
		while(l<cnt_a&&check(l,x,y)<0)l++;
		while(l>0&&check(l,x,y)>0)l--;


		if(check(l,x,y)!=0)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
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
+-+---+-
3 5

1
2*3+10
5*3

16
15

*/