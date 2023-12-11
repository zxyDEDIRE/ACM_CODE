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
//DR UL DL UR
const int dx[]={1,-1,1,-1};
const int dy[]={1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	string str;
	int n,m,x1,y1,x2,y2,op;
	cin>>n>>m>>x1>>y1>>x2>>y2>>str;
	if(str=="DR")op=0;
	else if(str=="UL")op=1;
	else if(str=="DL")op=2;
	else op=3;

	int cnt=0;
	int x=x1,y=y1;
	auto check=[&]()->bool{
		int a=(x2-x)/dx[op];
		int b=(y2-y)/dy[op];
		if(a==b&&a>=0)return 1;
		else return 0;
	};
	map<pair<int,pair<int,int>>,bool>mp;
	while(1)
	{
		if(mp.count({x,{y,op}}))break;
		mp[{x,{y,op}}]=1;
		//DR UL DL UR
		if(check()){
			cout<<cnt<<endl;
			return ;
		}
		if(op==0)
		{
			int a=n-x;
			int b=m-y;
			if(a==b)
				x=n,y=m,op=1;
			else if(a<b)
				x=n,y+=a,op=3;
			else if(a>b)
				x+=b,y=m,op=2;
		}
		else if(op==1)
		{
			int a=x-1;
			int b=y-1;
			if(a==b)
				x=1,y=1,op=0;
			else if(a<b)
				x=1,y-=a,op=2;
			else if(a>b)
				x-=b,y=1,op=3;
		}
		//DR UL DL UR
		else if(op==2)
		{
			int a=n-x;
			int b=y-1;
			if(a==b)
				x=n,y=1,op=3;
			else if(a<b)
				x=n,y-=a,op=1;
			else if(a>b)
				x+=b,y=1,op=0;
		}
		else if(op==3)
		{
			int a=x-1;
			int b=m-y;
			if(a==b)
				x=1,y=m,op=2;
			else if(a<b)
				x=1,y+=a,op=0;
			else if(a>b)
				x-=b,y=m,op=1;
		}
		cnt++;
	}
	cout<<-1<<endl;
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