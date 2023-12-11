/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int x,y;
bool check(int x,int y)
{
	// cout<<x<<" "<<y<<endl;
	int a=x/10*10+y/10;
	int b=x%10*10+y%10;
	// cout<<a<<" "<<b<<endl<<endl;
	if(a>=0&&a<24&&b>=0&&b<60)return 1;
	else return 0;
}
void solve()
{
	cin>>x>>y;
	for(int i=0;i<=360000;i++)
	{
		if(check(x,y)){
			cout<<x<<" "<<y<<endl;
			return ;
		}
		y++;
		if(y>=60)y=0,x++;
		if(x>=24)x=0;
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
}//20 00