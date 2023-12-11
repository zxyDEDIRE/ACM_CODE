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
	int fl;
	char ch;
	bool operator<(const node&a)const{
		if(a.fl!=fl)return a.fl<fl;
		else return a.ch<ch;
	}
};
map<node,int>mp;
set<int>s;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int fl;char ch;int x;
		cin>>fl>>ch>>x;
		mp[{fl,ch}]=x;
		s.insert(fl);
	}
	int ans=0;
	int flag=0;
	for(auto fl:s)
	{
		int a=mp[{fl,'L'}];
		int b=mp[{fl,'R'}];
		int c=mp[{fl,'*'}];
		if(a&&b)flag=1;
		if(c>=2)flag=1;
		if((a||b)&c)flag=1;
		int ma=0;
		ma=max({a,b});
		if(c)ma=max(ma,1ll);
		ans+=ma;
	}
	if(!flag)cout<<-1<<endl;
	else cout<<ans+1<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}